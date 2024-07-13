#include<iostream>
using namespace std;

int main(){
   int n;
   cout<<"enter the size of the array"<<endl;
   cin>>n;

   int arr[100];

   for(int i=0;i<n;i++){
    cin>>arr[i];
   }

   int x;
   cout<<"enter target sum"<<endl;
   cin>>x;

int count=0;
   for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        for(int k=j+1;k<n;k++){
        if(arr[i]+arr[j]+arr[k]==x){
            count++;
        }
        }
    }
   }

   cout<<count;
}