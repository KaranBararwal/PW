#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter the size of array "<<endl;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++){
        cout<<"enter the "<<i<<" element"<<endl;
        cin>>arr[i];
    }
int max=0;
    for(int i=0;i<n;i++){
        if(arr[i]>max){ //only one sign of >
            max=arr[i];
        }
    }

    cout<<"maximum element is "<<max<<endl;

    int min=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]<min){
            min=arr[i];
        }
    }

     cout<<"minimum element is "<<min<<endl;
     
    int sum=max+min;
    cout<<"sum is "<<sum;
}