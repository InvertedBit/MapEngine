#include "../inc/Logger.h"
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

}

Logger::~Logger()
{

}

void Logger::log(string s, LogLevel level)
{
  cout << s << endl;
}
