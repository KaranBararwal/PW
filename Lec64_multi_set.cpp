#include<iostream>
#include<set>
using namespace std;

int main(){

    multiset<int> ms; // allows duplicate value (ordered set)
    ms.insert(1);
    ms.insert(3);
    ms.insert(2);
    ms.insert(3);

    for(auto value : ms){
        cout<<value<<" ";
    }cout<<endl;
}