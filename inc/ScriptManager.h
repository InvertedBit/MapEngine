#ifndef SCRIPTMANAGER_H
#define SCRIPtMANAGER_H

namespace Common
{
    class ScriptManager
    {
    private:
        static ScriptManager Instance;
        map scripts;
        loadScripts(string path, bool checkIsSigned);
        ScriptManager();
    public:
        Initialize();
        ReloadScripts();
    };
}

#endif