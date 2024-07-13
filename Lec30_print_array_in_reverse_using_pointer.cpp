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

    int *ptr=&arr[n-1];
    
    while(1){
        cout<<*ptr<<"  ";
         
         if(ptr==arr){
            break;
         }
         ptr--;
    }

}