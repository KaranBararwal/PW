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

    int *ptr=arr;

    int sum=0;
    for(int i=0;i<n;i++){
        sum+=*(ptr+i);
    }
    cout<<"sum of array is "<<sum;
}