#ifndef SCRIPT_H
#define SCRIPT_H

#include <string>
#include "../submodules/Selene/include/selene.h"

using namespace std;
using namespace sel;

namespace Common
{
    class Script
    {
    private:
        bool isSigned;
        bool signatureRequired;
        State state;
        string path;
        void initialize();
    public:
        Script(string path,bool signatureRequired);
        void Reload();
    };
}

#endif