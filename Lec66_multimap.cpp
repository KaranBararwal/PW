#include<iostream>
#include<map>

using namespace std;

int main(){

    multimap<string,int>  directory;
    // stores multiple keys in oredered way
    // in multimap we can't use square bracket insertion

    directory.insert(make_pair("urvi",45345345));
    directory.insert(make_pair("sanghvi",34534253));
    directory.insert(make_pair("urvi",3464654));

    for(auto pair : directory){
        cout<<"Name-> "<<pair.first<<endl;
        cout<<"Phone no.->"<<pair.second<<endl<<endl;
    }
    return 0;
}