#include<bits/stdc++.h>int n;
    
using namespace std;

int main(){
    
int n;
    cout<<"enter the first number "<<endl;
    cin>>n;

    int m;
    cout<<"enter the second number "<<endl;
    cin>>m;

    int *ptr1=&n;
    int *ptr2=&m;
    int c;
    c=*ptr1;
    *ptr1=*ptr2;
    *ptr2=c;

    cout<<"now first number is "<<n<<" and second number is "<<m;

}