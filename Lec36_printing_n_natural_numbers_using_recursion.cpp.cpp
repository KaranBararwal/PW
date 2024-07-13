#include<iostream>
using namespace std;

void print(int n){
    //base case
    if(n<1){
        return ;
    }
   // assumption that print n-1 numbers first then it will print the n'th number
   // dont write cout<<print(n-1) directly
    print(n-1);
    cout<<n<<" ";
}

int  main(){
    int n;
    cout<<"enter the number "<<endl;
    cin>>n;

    print(n);
}