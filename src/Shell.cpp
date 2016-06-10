#include <sstream>
#include <iterator>
#include <iostream>
#include <string>
#include <future>
#include <numeric>
#include <cstring>
#include "../inc/Shell.h"
#include "../inc/Logger.h"
#include "../inc/Config.h"
#include "../submodules/linenoise-ng/linenoise.h"

using namespace std;
using namespace Common;


void Shell::completionCallback(char const* prefix, linenoiseCompletions* lc)
{
    map<string,function<string(vector<string>)>> commands = Shell::GetCommands();
    
    std::map<string,function<string(vector<string>)>>::const_iterator it;
    
    for (it = commands.begin(); it != commands.end(); ++it)
    {
        const char* cmp = it->first.c_str();
        if (strncmp(cmp, prefix, strlen(prefix)) == 0)
        {
            linenoiseAddCompletion(lc, cmp);
        }
    }
}


Shell Shell::instance;
map<string,function<string(vector<string>)>> commands;

Shell::Shell()
{
    RegisterCommand("engine.shutdown", &Shutdown);
}

Shell::~Shell()
{
    linenoiseHistorySave(historyFile);
    linenoiseHistoryFree();
}




//const char* hintCallback(const char *buf, int *color, int *bold); //TODO: implement hints

void Shell::loop(char const* prompt)
{
    Logger::Log("Starting shell loop...", LogLevel::DEBUG);
    running = true;
    while (running)
    {
        char* commandOrig = linenoise(prompt);
        string commandString(commandOrig);
        
        stringstream commandStringStream(commandString);
        
        istream_iterator<string> begin(commandStringStream);
        istream_iterator<string> end;
        
        vector<string> arguments(begin,end);
        
        if(arguments.size() == 0)
            continue;
        
        string command(arguments[0]);
        arguments.erase(arguments.begin());
        
        
        
        if(commands.find(command) == commands.end())
        {
            
        }else
        {
            RunCommand(command,arguments);
        }
    
   
        //cout << "thanks for the input:" << result << endl;
        linenoiseHistoryAdd(commandOrig);
        free(commandOrig);
    }
}
/*
string Shell::getCommandName(ShellCommand commandCallback)
{
    std::map<string, ShellCommand>::const_iterator it;
    
    for (it = commands.begin(); it != commands.end(); ++it)
    {
        if (it->second == value)
        {
            return it->first;
        }
    }
    return "";
}
*/
future<void> Shell::Start()
{
    linenoiseInstallWindowChangeHandler();
    
    instance.historyFile = Config::Get("shell.history").c_str();
    
    linenoiseHistoryLoad(instance.historyFile);
    linenoiseSetCompletionCallback(Shell::completionCallback);
//    linenoiseSetHintsCallback(hints);
    
    char const* prompt = "\x1b[1;32mMapEngine\x1b[0m> ";
    
    future<void> promise( async(&Shell::loop,instance,prompt));

}

void Shell::RegisterCommand(string name, function<string(vector<string>)> commandCallback)
{
    instance.commands[name] = commandCallback;
}

map<string,function<string(vector<string>)>> Shell::GetCommands()
{
    return instance.commands;
}

void Shell::RunCommand(string command, vector<string> params)
{
    string s;
    s = accumulate(begin(params), end(params), s);
    Logger::Log("Running Command: " + command + " with params: " + s, LogLevel::DEBUG);
    cout << instance.commands[command](params) << endl;
}

string Shell::Shutdown(vector<string> params)
{
    string ret("Shutting down...");
    instance.running = false;
    return ret;
}