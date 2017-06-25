#ifndef _MY_SHARED_PTR_H_
#define _MY_SHARED_PTR_H_
template <class int_var>
class MySharedPtr
{
public:

    MySharedPtr(const int_var* value);
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



#endif // _MY_SHARED_PTR_H_
