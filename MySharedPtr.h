#ifndef _MY_SHARED_PTR_H_
#define _MY_SHARED_PTR_H_


//*************************************************************************
//* implementing a generic pointer class.
//* the implementation is just after declaration out of the class block.
//*************************************************************************

template <class int_var>
class MySharedPtr
{

public:

    MySharedPtr(int_var* value);
    MySharedPtr(const MySharedPtr& org_obj);
    ~MySharedPtr();
    MySharedPtr& operator=(const MySharedPtr& org_obj);
    int_var& operator*();
    int_var* operator->();
    int_var* get();

private:
    int_var* value_;
    int*  counter_;
};


//*************************************************************************
//* Function name: MySharedPtr (int_var* value)
//* Description: contractor by pointer.
//* Parameters:
//*		value – pointer to ‘int_var’ Class.
//* Return Value: none.
//*************************************************************************

template <class int_var>
MySharedPtr<int_var>::MySharedPtr(int_var* value): value_(value){
    counter_ = new int;
    (*counter_) = 1;
}


//*************************************************************************
//* Function name: MySharedPtr (const MySharedPtr<int_var>& org_obj)
//* Description: copy constractor
//* Parameters:
//*		org_obj – an MySharedPtr<int_var> object.
//* Return Value: none.
//*************************************************************************

template <class int_var>
MySharedPtr<int_var>::MySharedPtr(const MySharedPtr<int_var>& org_obj): value_(org_obj.value_), counter_(counter_=org_obj.counter_){
    (*counter_)++;
}


//*************************************************************************
//* Function name: ~MySharedPtr
//* Description: distractor
//* Parameters: none.
//* Return Value: none.
//*************************************************************************

template <class int_var>
MySharedPtr<int_var>::~MySharedPtr(){
    (*counter_)--;
    if ((*counter_) == 0){
        delete value_;
        delete counter_;
    }
}


//*************************************************************************
//* Function name: operator=
//* Description: copies one MySharedPtr<int_var> to anther and handling the case of
//*		dangling memories.
//* Parameters:
//*		org_obj – an MySharedPtr<int_var> object – the origin object
//* Return Value: none.
//*************************************************************************

template <class int_var>
MySharedPtr<int_var>& MySharedPtr<int_var>::operator=(const MySharedPtr& org_obj){
    if (this != &org_obj){
        (*counter_)--;
        if ((*counter_) == 0){
            delete value_;
            delete counter_;
        }
        value_ = org_obj.value_;
        counter_=org_obj.counter_;
        (*counter_)++;
    }
    return *this;
}


//*************************************************************************
//* Function name: operator*
//* Description: returns the MySharedPtr<int_var> object value.
//* Parameters: none.
//* Return Value: an int_var class reference.
//*************************************************************************

template <class int_var>
int_var& MySharedPtr<int_var>::operator*() {
    return *value_;
}


//*************************************************************************
//* Function name: operator->
//* Description: returns the MySharedPtr<int_var> object value ponter.
//* Parameters: none.
//* Return Value: an int_var class pointer.
//*************************************************************************

template <class int_var>
int_var* MySharedPtr<int_var>::operator->() {
    return value_;
}


//*************************************************************************
//* Function name: get
//* Description: returns the MySharedPtr<int_var> object value ponter.
//* Parameters: none.
//* Return Value: an int_var class pointer.
//*************************************************************************

template <class int_var>
int_var* MySharedPtr<int_var>::get() {
    return value_;
}



#endif // _MY_SHARED_PTR_H_
