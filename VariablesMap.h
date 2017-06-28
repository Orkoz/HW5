#ifndef _VARIABLES_MAP_H_
#define _VARIABLES_MAP_H_
#define VALID_VAR_CHARS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_"

#include "Variable.h"
#include "MySharedPtr.h"
#include <map>
#include <vector>
#include <iostream>
#include <string>
#include <list>

using namespace std;


class VariablesMap{
public:
    VariablesMap();
    ~VariablesMap();
    void SetSavedName(const string& newSavedName);
    string& GetTmpVariable();
    void ClearTmpVars();
    VarPtr Operator(const string& x);
    VarPtr& at(const string& x);
    void erase(const string& x);

private:
    string SavedName_;
    map<string,VarPtr> StringToVarMap_;
    string valid_chars_;
    list<string> tmpVarList_;
};

#endif // _VARIABLES_MAP_H_
