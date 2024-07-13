#include<iostream>
using namespace std;

void multiple(int n,int k){
     if(k<1){
        return ;
     }

     multiple(n,k-1);
     cout<<n*k<<"  ";
}

int main(){
    int n;
    int k;
    cout<<"enter number and multiple"<<endl;
    cin>>n>>k;

    multiple(n,k);
}