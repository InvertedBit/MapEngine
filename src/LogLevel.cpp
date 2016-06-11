#include "../inc/LogLevel.h"
#include "../inc/Logger.h"

using namespace std;
using namespace Common;

map<string,LogLevel*> LogLevel::levels;

LogLevel::LogLevel(string nm, int gv)
{
    name = nm;
    gravity = gv;
}

void LogLevel::initialize()
{
    levels.clear();
    
    levels.insert( pair<string,LogLevel*>("DEBUG", new LogLevel("DEBUG",0)));
    levels.insert( pair<string,LogLevel*>("INFO", new LogLevel("INFO",1)));
    levels.insert( pair<string,LogLevel*>("WARNING", new LogLevel("WARNING",2)));
    levels.insert( pair<string,LogLevel*>("ERROR", new LogLevel("ERROR",3)));
    levels.insert( pair<string,LogLevel*>("FATAL", new LogLevel("FATAL",4)));
}

LogLevel* LogLevel::Get(string name)
{
    if(levels.size() == 0)
        initialize();
    
    //TODO: str to lower
    if(levels.find(name) == levels.end())
    {
        Logger::Log("LogLevel '"+name+"' not found.",levels["WARNING"]);
        return levels["WARNING"];
    }    
    return levels[name];
}

string LogLevel::ToString()
{
    return this->name;
}