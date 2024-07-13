#include<iostream>
using namespace std;

int swap(int *x,int *y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
int main(){
    int n;
    cout<<"enter the first number "<<endl;
    cin>>n;
    
    int m;
    cout<<"enter the second number "<<endl;
    cin>>m;

    int *ptr1=&n;
    int *ptr2=&m;

    swap(ptr1,ptr2);
    cout<<"now first number is "<<n<<" and second number is "<<m;
}