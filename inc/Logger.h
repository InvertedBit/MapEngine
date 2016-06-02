#ifndef LOGGER_H
#define LOGGER_H

#include <string>

using namespace std;

namespace Common
{

  enum LogLevel {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    FATAL,
  };

  class Logger
  {
  private:
    static bool instanceFlag;
    static Logger* instance;
    Logger();
    ~Logger();
    void log(string s, LogLevel level);
  public:
    static void Log(string s, LogLevel level);
  };
}

#endif
