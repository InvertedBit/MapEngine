#ifndef SCRIPT_H
#define SCRIPT_H

#include <string>
#include "../submodules/Selene/include/selene.h"

using namespace std;
using namespace Sel;

namespace Common
{
    class Script
    {
    private:
        bool signed;
        State state;
    public:
        Script(string path,bool signatureRequired);
    };
}

#endif