#include "../inc/Logger.h"
#include <iostream>
#include <string>

using namespace Common;
using namespace std;

bool Logger::instanceFlag = false;
Logger* Logger::instance = NULL;

void Logger::Log(string s, LogLevel level)
{
  if(!instanceFlag)
  {
    instance = new Logger();
    instanceFlag = true;
  }
  instance->log(s, level);
}

Logger::Logger()
{

}

Logger::~Logger()
{
  instanceFlag = false;
}

void Logger::log(string s, LogLevel level)
{
  cout << s << endl;
}
