#include<iostream>
using namespace std;

int check(int n,int arr[]){
  int missing=-1;
  int sum=0;
  for(int i=0;i<n;i++){
    sum+=arr[i];
  
  }
  int real_sum=n*(n+1)/2;
  missing=real_sum-sum;
  return missing;

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

   int c=check(n,arr);
   cout<<"missing element is "<<c;

}