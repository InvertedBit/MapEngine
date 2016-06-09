#include <vector>
#include <functional>
#include <map>
#include <string>
#include "../submodules/linenoise-ng/linenoise.h"

using namespace std;

namespace Common
{
    
    class Shell
    {
    private:
        static Shell instance;
        bool running;
        map<string,function<string(vector<string>)>> commands;
        
        Shell();
        ~Shell();
//        string getCommandName(function<string> commandCallback);
        static void completionCallback(char const* prefix, linenoiseCompletions* lc);
        //const char* hintCallback(const char *buf, int *color, int *bold); //TODO: implement hints
        void loop(char const* prompt);
    public:
        static void Start();
        static void RegisterCommand(string name, function<string(vector<string>)> commandCallback);
        static map<string,function<string(vector<string>)>> GetCommands();
        static void RunCommand(string command, vector<string> params);
        static string Shutdown(vector<string>);
    };
    
}