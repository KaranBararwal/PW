#include<iostream>
using namespace std;

int main(){
    cout<<"wild pointer"<<endl;
    int *ptr1;
    cout<<ptr1<<endl;

    cout<<"NULL pointer"<<endl;
    int *ptr2=NULL;
    cout<< ptr2<<endl;

    cout<<"dangling pointer"<<endl;
     int *ptr3 = NULL;
    {
        int x = 10;
        ptr3 = &x;
    }
    // it will not print the value of address of x
    cout<<*ptr3<<endl;

    cout<<"void pointer"<<endl;
    int val1=10;
    float val2= 10.2;
    void *ptr4=&val1;
    ptr4=&val2;

    // we have to typecast the value for printing
    int *intergerPointer = (int *)ptr4;

     cout<<*intergerPointer<<endl;

}