#include "MySharedPtr.h"

template <class int_var>
MySharedPtr<int_var>::MySharedPtr(const int_var* value){
    value_ = value;
    counter_ = new int;
    (*counter_)++;
}

template <class int_var>
MySharedPtr<int_var>::MySharedPtr(const MySharedPtr& org_obj){
    value_ = org_obj.value_;
    counter_=org_obj.counter_;
    (*counter_)++;
}

template <class int_var>
MySharedPtr<int_var>::~MySharedPtr(){
    (*counter_)--;
    if ((*counter_) == 0){
        delete value_;
        delete counter_;
    }
}

template <class int_var>
MySharedPtr<int_var>& MySharedPtr<int_var>::operator=(const MySharedPtr& org_obj){
    if (this != &org_obj){
        value_ = org_obj.value_;
        if ((*counter_) == 1){
            delete value_;
            delete counter_;
        }
        counter_=org_obj.counter_;
        (*counter_)++;
    }
    return *this;
}

template <class int_var>
int_var& MySharedPtr<int_var>::operator*() {
    return *value_;
}

template <class int_var>
int_var* MySharedPtr<int_var>::operator->() {
    return value_;
}

template <class int_var>
int_var* MySharedPtr<int_var>::get() {
    return value_;
}
