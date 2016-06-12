#ifndef SCRIPTMANAGER_H
#define SCRIPTMANAGER_H

#include <string>
#include <map>
#include "Script.h"

namespace Common
{
    class ScriptManager
    {
    private:
        static ScriptManager instance;
        map<string,Script*> scripts;
        void loadScripts(string path, bool checkIsSigned);
        ScriptManager();
    public:
        static void Initialize();
        static void ReloadScripts();
        static Script* GetScript(string name);
        static map<string,Script*>* GetAllScripts();
    };
}

#endif