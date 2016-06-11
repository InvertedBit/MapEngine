#include "../inc/LogEntry.h"

using namespace std;
using namespace Common;

LogEntry::LogEntry(string msg, LogLevel* lvl)
{
    message = msg;
    level = lvl;
}

string LogEntry::ToString()
{
    return level->ToString() + ": " + message;
}