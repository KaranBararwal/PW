#include<iostream>
using namespace std;

int main(){
int m,n;

cout<<"enter the size of first array"<<endl;
cin>>n;
int arr1[n];
for(int i=0;i<n;i++){
    cout<<"enter "<<i<<"element"<<endl;
    cin>>arr1[i];
}

cout<<"enter the size of second array"<<endl;
cin>>m;
int arr2[m];
for(int i=0;i<m;i++){
    cout<<"enter "<<i<<"element"<<endl;
    cin>>arr2[i];
}

int ARR[m+n];

int i=0;
int j=0;
int k=0;
while(i<n || j<m){
   if(arr1[i]<arr2[j]){
    ARR[k]=arr1[i];
    i++;
   }
   else{
    ARR[k]=arr2[j];
    j++;
   }
   k++;
}

for(int i=0;i<m+n;i++){
    cout<<ARR[i]<<" ";
}


   return 0;
}