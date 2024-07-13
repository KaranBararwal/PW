#include<iostream>
using namespace std;

void rev(int n , int arr[]){
    int start=0;
    int end=n-1;
   
  while(start<end){
    int ex;
    ex=arr[start];
    arr[start]=arr[end];
    arr[end]=ex;
    
    start++;
    end--;
  }
 
}
int main(){
    int n;
    cout<<"enter the size of array "<<endl;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++){
        cout<<"enter the "<<i<<" element"<<endl;
        cin>>arr[i];
    }

    rev(n,arr);
     for(int i=0;i<n;i++){
    cout<<arr[i]<<endl;
  }
  
}