#include<iostream>
using namespace std;

int  AlternativeSum(int n){
   if(n==0){
    return 0;
   }
   
   return AlternativeSum(n-1)+((n%2==0)?(-n):(n));
}

int main(){
    int n;
    cout<<"enter the number for sum "<<endl;
    cin>>n;

    cout<<"alternative sum is "<<AlternativeSum(n);

}