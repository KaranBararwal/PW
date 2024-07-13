#include<iostream>
using namespace std;

int recursion(int n){
    if(n==0){
        return 0;
    }
    else if(n==1){
        return 1;
    }
    else{
        return recursion(n-1)+recursion(n-2);
    }
}

int main(){
    int n;
    cout<<"enter the number for fibonacci series "<<endl;
    cin>>n;

   for(int i=0;i<n;i++){
    cout<< recursion(i)<<"  ";
   }
   
}