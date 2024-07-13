#include<iostream>
using namespace std;

int min(int n, int Arr[]){
 int min=Arr[0];
 for(int i=1;i<n;i++){
    if(Arr[i]<min){
        min=Arr[i];
    }
 }
 return min;
}


int main(){
    int n;
    cout<<"enter the size of array"<<endl;
    cin>>n;
    int arr[n];
    int ARR[n];
 
for(int i=0;i<n;i++){
    cout<<"enter the "<<i<<"element"<<endl;
    cin>>arr[i];
}
cout<<"for second array"<<endl;

for(int i=0;i<n;i++){
    cout<<"enter the "<<i<<"element"<<endl;
    cin>>ARR[i];
}

int m1=min(n,arr);   //here do not write min(n,arr[]) or min(n,arr[n])

cout<<"minimum element of first array "<<m1<<endl;

int m2=min(n,ARR);

cout<<"minimum element of second array "<<m2<<endl;

int msum=m1+m2;
cout<<"minimum sum is "<<msum;


}