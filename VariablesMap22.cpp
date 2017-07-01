#include"VariablesMap.h"
#include"ScriptExceptions.h"
#include <time.h>

#define VALID_ARRAY_LENGTH  62
#define VALID_ARRAY_LETTERS 51
using namespace std;

VariablesMap::VariablesMap() : saved_name_("0")
{
}
void VariablesMap::SetSavedName(const string & NewSavedName)
{
	saved_name_ = NewSavedName;
}
VarPtr& VariablesMap::operator[](const string & x)
{
	if(!isKeyLegal(x))
		throw INVALID_VAR_NAME(x);
	if(tmp_map_.find(x) != tmp_map_.end())
		return tmp_map_[x];
	return real_map_[x];
}
void VariablesMap::erase(const string & x)
{
	tmp_map_.erase(x);
	real_map_.erase(x);
}
VarPtr& VariablesMap::at(const string & x)
{
	try
	{
		return real_map_.at(x);
	}
	catch (std::exception&)
	{
		return tmp_map_.at(x);
	}
}
string VariablesMap::GetTmpVariable()
{	
	srand(time(NULL));
	char append_char = VALID_VAR_CHARS[rand() % VALID_ARRAY_LETTERS];
	string key_guess;
	key_guess += append_char;
	while (!(isKeyValid(key_guess)))
	{
		int letter = rand() % VALID_ARRAY_LENGTH;
		char append_char = VALID_VAR_CHARS[letter];
		key_guess = key_guess += append_char;
	}
	tmp_map_[key_guess] = *(new VarPtr());
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
				if (i == 0 && j > VALID_ARRAY_LETTERS)
					return false;
				break;

			}
		}
	}
	return true;
}
bool VariablesMap::isKeyValid(const string & x)
{
	if (x == saved_name_	 			    || 
		tmp_map_.find(x)  != tmp_map_.end() ||
		real_map_.find(x) != real_map_.end())
		return false;
	return true;
}