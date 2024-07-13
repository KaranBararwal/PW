#include<iostream>
using namespace std;

int main(){
  int n;
  cout<<"enter the size of the array"<<endl;
  cin>>n;
  int arr[n];

  for(int i=0;i<n;i++){
    cin>>arr[i];
  }


  int max=0;
  for(int i=0;i<n;i++){
    if(arr[i]>max){
    max=arr[i];
    }
  }
   cout<<"the maximum element is "<<max;
  return 0;
}