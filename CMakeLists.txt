# CMake file for CPP module demos

cmake_minimum_required(VERSION 2.8.0 FATAL_ERROR)

# the 'project' macro is used to name a project
project(MapEngine)


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
)
source_group("src" FILES ${SRCS})


# find headers (let them show up in the IDEs)
file(GLOB HDRS
    ./inc/*.h
    ./inc/*.hpp
)
source_group("inc" FILES ${HDRS})


# find packages and libs


# setup package headers


# setup debug/release libraries
set(LIBS_DEBUG
)

set(LIBS_RELEASE
)



# define target dependencies and build instructions
set(EXECUTABLE_NAME ${PROJECT_NAME})
add_executable(${EXECUTABLE_NAME} ${SRCS} ${HDRS})
target_link_libraries(${EXECUTABLE_NAME} ${LIBS_RELEASE} ${LIBS_DEBUG})
