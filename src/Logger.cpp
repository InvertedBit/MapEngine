#include "../inc/Logger.h"
#include "../inc/Config.h"
#include <iostream>
#include <string>

using namespace Common;
using namespace std;

Logger Logger::instance;



void Logger::Log(string s, LogLevel* level)
{
    instance.entries.push(LogEntry(s, level));
    instance.writeLog();
}

Logger::Logger()
{
}

Logger::~Logger()
{
    writeLog();
}

void Logger::writeLog()
{
    if(writingLog)
        return;
        
    writingLog = true;
    //TODO: Filter by loglevel
    while(!entries.empty())
    {
        cout << entries.front().ToString() << endl;
        entries.pop();
    }
    writingLog = false;
}
