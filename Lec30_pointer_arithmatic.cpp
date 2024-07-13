#include<iostream>
using namespace std;

int main(){
    int arr[]={1,2,3};
    int *ptr=&arr[0];

    cout<<ptr<<endl;


    //first it will give value at that pointer then increment the pointer
    cout<<*ptr++<<endl;

     cout<<ptr<<endl;

    cout<<endl<<"for second array"<<endl;

     int ARR[]={4,5,6};
     int *PTR=&ARR[0];

     cout<<PTR<<endl;

     //first it will get value at that pointer then increment the value
     cout<<(*PTR)++<<endl;
     cout<<PTR<<endl;
     cout<<ARR[0]<<"  "<<ARR[1]<<"  "<<ARR[2];

     cout<<endl<<"for third array"<<endl;
     
     int arr2[]={7,8};
     int *ptr2=&arr2[0];
    

    /*first it will increase the value of pointer(address of 0th element by pointer arithematic ) then 
    it will print value at that address it won't effect the values in array
    */
     cout<<*++ptr2<<endl;

     cout<<arr2[0]<<"  "<<arr2[1]<<endl;

     cout<<"for fourth array"<<endl;

    /*first it will get the value at that pointer then increase the value by one 
    it also effect the value at the array
    */
     cout<<++*ptr2<<endl;
     cout<<arr2[0]<<"  "<<arr2[1]<<endl;






}