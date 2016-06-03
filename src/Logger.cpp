#include "../inc/Logger.h"
#include "../inc/Config.h"
#include <iostream>
#include <string>

using namespace Common;
using namespace std;

Logger Logger::instance;



void Logger::Log(string s, LogLevel level)
{
  instance.log(s, level);
}

Logger::Logger()
{
  loglevels[LogLevel::DEBUG] = "DEBUG";
  loglevels[LogLevel::INFO] = "INFO";
  loglevels[LogLevel::WARNING] = "WARNING";
  loglevels[LogLevel::ERROR] = "ERROR";
  loglevels[LogLevel::FATAL] = "FATAL";
}

Logger::~Logger()
{

}

void Logger::log(string s, LogLevel level)
{
  //TODO: Filter by loglevel
  cout << Logger::loglevels[level] << ": " << s << endl;
}
