#include"VariablesMap.h"
#include"ScriptExceptions.h"
#include <stdexcept>

using namespace std;


//*************************************************************************
//* Function name: VariablesMap
//* Description: empty contractor – sets the Saved Var name in the valid characters.
//* Parameters: none.
//* Return Value: none.
//*************************************************************************

VariablesMap::VariablesMap(){
    SavedName_ = "_saved";
    valid_chars_ = VALID_VAR_CHARS;
}


//*************************************************************************
//* Function name: ~VariablesMap
//* Description: distractor
//* Parameters: none.
//* Return Value: none.
//*************************************************************************

VariablesMap::~VariablesMap() {
    SavedName_.clear();
    valid_chars_.clear();
    StringToVarMap_.clear();
}


//*************************************************************************
//* Function name: ~SetSavedName
//* Description: change the Saved Var name
//* Parameters:
//*		newSavedName – string type – the new Saved Var name.
//* Return Value: none.
//*************************************************************************

void VariablesMap::SetSavedName(const string& newSavedName) {
    SavedName_.clear();
    SavedName_ = newSavedName;
}


//*************************************************************************
//* Function name: GetTmpVariable
//* Description: finds a free valid variable name (start with one of the ABC and all characters are in the valid characters list).
//* Parameters: none.
//* Return Value: string type – the new variable name.
//*************************************************************************

//*************************************************************************
//* checks if ‘a’ is free, then checks ‘b’ and so on.
//* if none of the ABC is not free check ‘aa’ then ‘ab’..’ba’ , ‘bb’ and so on.
//* in the end go throw al the one or two characters combination that following the valid name rules.
//*************************************************************************

string VariablesMap::GetTmpVariable() {
    string tmp_name;
    char c= 'Z';
    for (unsigned int j = 0; j < valid_chars_.length(); ++j) {
        if ((valid_chars_[j] >= 'a')){
            for (unsigned int z = 0; z < valid_chars_.length(); ++z) {
                bool move_on = false;
                tmp_name += valid_chars_[z];
                list<string>::iterator it_list = tmpVarList_.begin();
                if (it_list == tmpVarList_.end()){
                    tmpVarList_.push_back(tmp_name);
                    return tmp_name;
                }
                for (; it_list != tmpVarList_.end(); ++it_list){
                    if (*it_list == tmp_name || tmp_name == SavedName_)
                            move_on = true;

                    if (!move_on) {
                        tmpVarList_.push_back(tmp_name);
                        return tmp_name;
                        }
                    }
                }
                tmp_name = valid_chars_[j];
            }
        }
    throw INVALID_VAR_NAME(tmp_name);
    }



//*************************************************************************
//* Function name: ClearTmpVars
//* Description: go throw the tmp variable list (a list which contain all the tmp variable names) and delete the match variable from the map.
//* Parameters: none.
//* Return Value: none.
//*************************************************************************

void VariablesMap::ClearTmpVars() { //*uses ‘map’ and ‘list’ functions.
    list<string>::iterator it_list = tmpVarList_.begin();
    map<string, VarPtr>::iterator it_map;
     while(it_list!=tmpVarList_.end()){
        it_map = StringToVarMap_.find(*it_list);
        if (it_map != StringToVarMap_.end()) {
            StringToVarMap_.erase(*it_list);
        }
         it_list = tmpVarList_.erase (it_list); //* the iterator ‘it’ moves automatically to the next element (equals to it++).
     }
}


//*************************************************************************
//* Function name: Operator[]
//* Description: if ‘x’ is a valid variable name (start with one of the ABC and all characters are in the valid characters list) then returns a new Variable referance.
//* Parameters:
//*		x – string type – the name of the new variable in the map object.
//* Return Value: VarPtr reference.
//*************************************************************************

VarPtr& VariablesMap::operator[](const string& x) {
    bool valid;
    if (x[0] < 'a')
        throw INVALID_VAR_NAME(x);

    if (x == SavedName_)
        throw INVALID_VAR_NAME(x);


    for (unsigned int i = 0; i < x.length() ; ++i) {
        valid = false;
        for (unsigned int j = 0; j < valid_chars_.length(); ++j) {
            if (valid_chars_[j] == x[i]){
                valid = true;
                break;
            }
        }
        if (!valid){
            throw INVALID_VAR_NAME(x);
        }
    }

    return StringToVarMap_[x] = *(new VarPtr);;
}


//*************************************************************************
//* Function name: at
//* Description: returns a reference to the Variable which ‘x’ is map to if x is a valid variable name.
//* Parameters:
//*		x – string type – the name of the variable in the map object.
//* Return Value: VarPtr reference.
//*************************************************************************

VarPtr& VariablesMap::at(const string &x) {
    map<string, VarPtr>::iterator it_map;
    it_map = StringToVarMap_.find(x);
    if (it_map == StringToVarMap_.end()) {
        throw std::out_of_range ("blah");
    }
    return it_map->second;
}


//*************************************************************************
//* Function name: erase
//* Description: erases the element with the name ‘x’
//* Parameters:
//*		x – string type – the name of the variable to be deleted.
//* Return Value: none.
//*************************************************************************

void VariablesMap::erase(const string &x) {
    StringToVarMap_.erase(x);
}







