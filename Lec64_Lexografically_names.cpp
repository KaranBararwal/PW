#include<iostream>
#include<set>
using namespace std;

int main(){

    set <string> inviteList;

    int n;
    cout<<"enter the number of total names "<<endl;
    cin>>n;
    
    cout<<"enter "<<n<<" names "<<endl;
    while(n--){

        string name;
        cin>>name;

        inviteList.insert(name);
    }
    cout<<"invite list "<<endl;
    for(auto name : inviteList){
        cout<<name<<endl;
    }
}