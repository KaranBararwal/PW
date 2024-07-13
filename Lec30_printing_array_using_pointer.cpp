#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter the size of array "<<endl;
    cin>>n;

    int arr[n];
   
    for(int i=0;i<n;i++){
        cout<<"enter "<<i<<" element "<<endl;
        cin>>arr[i];
    }
    
    int *ptr=&arr[0];

    int ele;
    cout<<"enter the index for element to be printed ";
    cin>>ele;
    
    cout<<*(ptr+ele);
}