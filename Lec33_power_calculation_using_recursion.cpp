#include<iostream>
using namespace std;

int power(int n,int p){
    if(p==0){
        return 1;
    }
   
    
    return n*power(n,p-1);
}
int main(){
    int n,p;
    cout<<"enter number and its power"<<endl;
    cin>>n>>p;

    cout<<power(n,p);

}