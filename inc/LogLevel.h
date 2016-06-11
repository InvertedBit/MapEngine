#ifndef LOGLEVEL_H
#define LOGLEVEL_H

#include <string>
#include <map>

using namespace std;

namespace Common
{
    class LogLevel
    {
    private:
        static void initialize();
        static map<string,LogLevel*> levels;
        string name;
        int gravity;
    public:
        LogLevel(string nm,int gv);
        static LogLevel* Get(string name);
        string ToString();
    };
}

#endif