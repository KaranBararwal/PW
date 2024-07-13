#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector <int> v;
    v={10,20,30,40};
    v.push_back(50);
    //v={10,20,30,40,50}
    v.pop_back();
    //v={10,20,30,40}
    v.insert(v.begin()+2,100);
    //v={10,20,100,30,40,50}
    v.erase(v.begin()+2);
    //v={10,20,30,40,50}
    v.clear();
    //v is empty

    
}
