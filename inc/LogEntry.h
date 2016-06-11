#ifndef LOGENTRY_H
#define LOGENTRY_H

#include <string>
#include "LogLevel.h"

using namespace std;

namespace Common
{
    class LogEntry
    {
    private:
        string message;
        LogLevel* level;
    public:
        LogEntry(string msg, LogLevel* lvl);
        string ToString();
    };
}

#endif