#ifndef _VARIABLES_MAP_H_
#define _VARIABLES_MAP_H_
#include <map>
#include <string>
#include "Variable.h"
#define RAND_MAX


#define VALID_VAR_CHARS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_"

using namespace std;

typedef map<string,VarPtr> Map;


class VariablesMap
{
public:
	VariablesMap();
	void SetSavedName(const string& NewSavedName);
	string GetTmpVariable();
	void ClearTmpVars() { tmp_map_.clear(); }
	VarPtr& operator[](const string& x);
	VarPtr& at(const string& x);
	void erase(const string& x);

private:
	bool isKeyLegal(const string& x);
	bool isKeyValid(const string& x);
	Map tmp_map_;
	Map real_map_;
	string saved_name_;
};
#endif // _VARIABLES_MAP_H_
