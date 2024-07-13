#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter the number for sum "<<endl;
    cin>>n;
    int sum=0;
    if(n%2==0){
        sum=(n/2)*(-1);
    }
    else{
        sum=(n/2)*(-1)+n;
    }
    cout<<"sum is "<<sum;
}

