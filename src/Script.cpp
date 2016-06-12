#include "../inc/Script.h"

using namespace std;
using namespace Common;
using namespace sel;

void Script::initialize()
{
    if(signatureRequired) {
        //TODO: Implement signature checks
    }else {
        state.Load(path);
    }
}

Script::Script(string scriptPath, bool sigRequired)
{
    path = scriptPath;
    signatureRequired = sigRequired;
    initialize();
}

void Script::Reload()
{
    state = State();
    initialize();
}
