#include"VariablesMap.h"
#include"ScriptExceptions.h"
#include <time.h>

using namespace std;

//*************************************************************************
//* Function name: VariablesMap
//* Description: empty contractor – sets the Saved Var name in the valid characters.
//* Parameters: none.
//* Return Value: none.
//*************************************************************************

VariablesMap::VariablesMap(): SavedName_("_saved"){}

//*************************************************************************
//* Function name: ~SetSavedName
//* Description: change the Saved Var name
//* Parameters:
//*		newSavedName – string type – the new Saved Var name.
//* Return Value: none.
//*************************************************************************

void VariablesMap::SetSavedName(const string& newSavedName){
    SavedName_ = newSavedName;
}


VarPtr& VariablesMap::operator[](const string & x){
    if (!isKeyLegal(x))
        throw INVALID_VAR_NAME(x);

    return StringToVarMap_[x];
}


void VariablesMap::erase(const string & x){
	StringToVarMap_.erase(x);
}

void VariablesMap::ClearTmpVars(){
    for (unsigned int i = 0; i < tmpVarList_.size(); ++i) {
        StringToVarMap_.erase(tmpVarList_[i]);
    }
    tmpVarList_.clear();
}


VarPtr& VariablesMap::at(const string & x){
    return StringToVarMap_.at(x);
}


string VariablesMap::GetTmpVariable()
{	
	srand(time(NULL));
	char append_char = VALID_VAR_CHARS[rand() % 51];
	string key_guess;
	key_guess += append_char;
	while (key_guess == SavedName_ || StringToVarMap_.find(key_guess) != StringToVarMap_.end())
	{
		int letter = rand() % 62;
		char append_char = VALID_VAR_CHARS[letter];
		key_guess = key_guess += append_char;
	}
    tmpVarList_.push_back(key_guess);
    StringToVarMap_[key_guess] = *(new VarPtr());
	return key_guess;
}


bool VariablesMap::isKeyLegal(const string & x)
{
	int i,j;
	char test;
	for (i = 0; i < x.size(); i++)
	{
		for (j = 0; j <= 64; j++)
		{
			if (j == 64)
				return false;
			test = VALID_VAR_CHARS[j];
			if (x[i] == test)
			{
				if (i == 0 && j > 51)
					return false;
				break;

			}
		}
	}
	return true;
}
