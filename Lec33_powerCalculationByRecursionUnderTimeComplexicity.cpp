#include<iostream>
using namespace std;

int power(int n,  int p){
    if(p==0){
        return 1;
    }
    if(p%2==0){
        int result=power(n,p/2);
        return result*result;
    }
    else{
        int result=power(n,(p-1)/2);
            return n*result*result;
        }
    }


int main(){
    int n,p;
    cout<<"enter the number and the power "<<endl;
    cin>>n>>p;

    cout<<power(n,p);
}