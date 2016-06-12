# CMake file for CPP module demos

cmake_minimum_required(VERSION 2.8.0 FATAL_ERROR)

# the 'project' macro is used to name a project
project(MapEngine)
set(CMAKE_C_COMPILER g++-5)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++14" COMPILER_SUPPORTS_CXX14)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX14)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
elseif(COMPILER_SUPPORTS_CXX11)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
        message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -lpthread")


# adjust some global CMake configuration settings
set(CMAKE_VERBOSE_MAKEFILE TRUE)
set(CMAKE_COLOR_MAKEFILE TRUE)
set(CMAKE_SUPPRESS_REGENERATION TRUE)
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(CMAKE_PREFIX_PATH "${CMAKE_HOME_DIRECTORY}/_LIBS;${CMAKE_PREFIX_PATH}")


if(CMAKE_CONFIGURATION_TYPES)
   set(CMAKE_INSTALL_PREFIX ./install)
   set(CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}" CACHE STRING
     "Reset the configurations to what we need"
     FORCE)
endif()

if(CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_CONFIGURATION_TYPES Debug Release)
    set(CMAKE_CONFIGURATION_TYPES "${CMAKE_CONFIGURATION_TYPES}" CACHE STRING
      "Reset the configurations to what we need"
      FORCE)
endif()


# configure the Visual Studio user file
if(WIN32)
   if(MSVC)
	# find user and system name
	set(VC_USER_SYSTEM_NAME $ENV{USERDOMAIN} CACHE STRING SystemName)
	set(VC_USER_USER_NAME $ENV{USERNAME} CACHE STRING UserName)

	# configure the template file
	set(USER_FILE ${PROJECT_NAME}.vcxproj.user)
	set(OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR}/${USER_FILE})

	# setup working directories in template file
	set(USERFILE_WORKING_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}/bin/Debug)
	set(USERFILE_WORKING_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/bin/Release)
	set(USERFILE_ARGUMENTS_RELEASE "")
	set(USERFILE_ARGUMENTS_DEBUG "")
	configure_file(${CMAKE_HOME_DIRECTORY}/_CMAKE/CPP-PROJECTS.vcxproj.usertemplate ${OUTPUT_PATH} @ONLY)
   endif(MSVC)
endif(WIN32)


# check for Linux and make output path adjustments
if ("${CMAKE_SYSTEM}" MATCHES "Linux.*")
  #Set the binary output path to correspond to windows defaults
  set(EXECUTABLE_OUTPUT_PATH "${EXECUTABLE_OUTPUT_PATH}/${CMAKE_BUILD_TYPE}")
endif()


# find sources
file(GLOB SRCS
    ./src/*.c
    ./src/*.cpp
    ./submodules/linenoise-ng/ConvertUTF.cpp
    ./submodules/linenoise-ng/wcwidth.cpp
    ./submodules/linenoise-ng/linenoise.cpp
)
source_group("src" FILES ${SRCS})


# find headers (let them show up in the IDEs)
file(GLOB HDRS
    ./inc/*.h
    ./inc/*.hpp
    ./submodules/linenoise-ng/ConvertUTF.h
    ./submodules/linenoise-ng/linenoise.h
    ./submodules/Selene/include/selene.h
    ./submodules/Selene/include/selene/*.h
)
source_group("inc" FILES ${HDRS})


# find packages and libs
find_package( Boost REQUIRED COMPONENTS regex )
include_directories( ${Boost_INCLUDE_DIRS} )
find_package (Threads REQUIRED)
find_package( Lua REQUIRED )
include_directories( ${LUA_INCLUDE_DIR} )


add_library(LinenoiseNg ./submodules/linenoise-ng/ConvertUTF.h ./submodules/linenoise-ng/linenoise.h ./submodules/linenoise-ng/ConvertUTF.cpp ./submodules/linenoise-ng/wcwidth.cpp ./submodules/linenoise-ng/linenoise.cpp)

file(GLOB Selene_HDRS
    ./submodules/Selene/include/selene.h
    ./submodules/Selene/include/selene/*.h
)

#source_group(Selene_HDRS_grp FILES )

include_directories( submodules/Selene/include )


# setup package headers


# setup debug/release libraries

set(LIBS_RELEASE
${Boost_REGEX_LIBRARY}
${CMAKE_THREAD_LIBS_INIT}
LinenoiseNg
${LUA_LIBRARIES}
)

set(LIBS_DEBUG
${LIBS_DEBUG}
${Boost_REGEX_LIBRARY}
${CMAKE_THREAD_LIBS_INIT}
LinenoiseNg
${LUA_LIBRARIES}
)


# define target dependencies and build instructions
set(EXECUTABLE_NAME ${PROJECT_NAME})
add_executable(${EXECUTABLE_NAME} ${SRCS} ${HDRS})
target_link_libraries(${EXECUTABLE_NAME} optimized ${LIBS_RELEASE} debug ${LIBS_DEBUG})
