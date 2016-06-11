#include "../inc/Config.h"
#include "../inc/Logger.h"
#include <string>
#include <map>
#include <fstream>
#include <boost/regex.hpp>
#include <iostream>

using namespace Common;
using namespace std;
using namespace boost;

Config Config::instance;

string Config::Get(string name)
{
  if(instance.configs.find(name) != instance.configs.end())
  {
    return instance.configs[name];
  }
  return "";
}

void Config::Set(string name, string value)
{
  instance.configs[name] = value;
}

void Config::Load(string content)
{
  instance.configs.clear();
  Logger::Log("Loading config from string",LogLevel::Get("DEBUG"));
  regex exp("([a-z\\.]+)(?:=)([a-zA-z0-9\\/\\\\]+)(?:;)");
  string::const_iterator start, end;
  match_results<string::const_iterator> match;
  match_flag_type flags = match_default;


  bool isValue = false;

  start = content.begin();
  end = content.end();

  while(regex_search(start, end, match, exp, flags))
  {
    instance.configs[match[1]] = match[2];
    Logger::Log("Loading Setting: " + match[1] + "=" + match[2], LogLevel::Get("DEBUG"));

    start = match[0].second;

    flags |= match_prev_avail;
    flags |= match_not_bob;

  }
}

void Config::LoadFile(string name)
{
  ifstream ifs(name);
  string content((istreambuf_iterator<char>(ifs)),(istreambuf_iterator<char>()));
  Load(content);
}
