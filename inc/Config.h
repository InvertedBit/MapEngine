#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <map>

using namespace std;

namespace Common
{
  class Config
  {
  public:
    static void Load(string s);
    static void LoadFile(string name);
    static string Get(string name);
    static void Set(string name, string value);
  private:
    map<string,string> configs;
    static Config instance;
  };
}

#endif
