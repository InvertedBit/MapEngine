#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <map>

using namespace std;

namespace Common
{

  enum LogLevel {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    FATAL
  };

  class Logger
  {
  private:
    static Logger instance;
    Logger();
    ~Logger();
    void log(string s, LogLevel level);
    map<LogLevel,string> loglevels;
  public:
    static void Log(string s, LogLevel level);
  };
}

#endif
