#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[100];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
int max=arr[0];
int min=arr[0];

for(int i=1;i<n;i++){
    if(arr[i]>arr[i-1]){
    max=arr[i];
    }
}
for(int i=1;i<n;i++){
    if(arr[i]<arr[i-1]){
        min=arr[i];
    }
}
int sum=max+min;
cout<<"maximum number in array is "<<max<<endl<<"minimum number in array is "<<min<<endl<<"sum is "<<sum;
}

