#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <map>
#include <queue>
#include <mutex>
#include "LogEntry.h"

using namespace std;

namespace Common
{

  class Logger
  {
  private:
    static Logger instance;
    bool writingLog;
    Logger();
    ~Logger();
    void writeLog();
    queue<LogEntry> entries;
    mutex writeLogLock;
  public:
    static void Log(string s, LogLevel* level);
  };
}

#endif
