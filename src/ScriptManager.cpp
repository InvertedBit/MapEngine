#include "../inc/ScriptManager.h"
#include "../inc/Logger.h"

using namespace std;
using namespace Common;

ScriptManager ScriptManager::instance;

ScriptManager::ScriptManager()
{}

void ScriptManager::Initialize()
{}

void ScriptManager::ReloadScripts()
{
    for(auto const entry : instance.scripts)
    {
        entry.second->Reload();
    }
}

Script* ScriptManager::GetScript(string name)
{
    if(instance.scripts.find(name) == instance.scripts.end())
    {
        Logger::Log("Script '" + name + "' not found.",LogLevel::Get("WARNING"));
        return NULL;
    }
    return instance.scripts[name];
}

map<string,Script*>* ScriptManager::GetAllScripts()
{
    map<string,Script*>* scriptsPtr = &instance.scripts;
    return scriptsPtr;
}