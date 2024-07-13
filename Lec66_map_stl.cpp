#include<iostream>
#include<map>
using namespace std;

int main(){

    map <string , int > directory; // <key data type , value data type>
    // for decending order 
    // map <string,int,greater<string>  > directory;  

    directory["naman"] = 3876;
    directory["animesh"] = 489654;
    directory["ritu"] = 38979;

    directory.insert(make_pair("damam",87564));
    
    // duplicate values are not allowed but we can update value by using same key with different value
    for(auto element : directory){

        cout<<"Name->"<<element.first<<endl; // for key
        cout<<"Phone no.->"<<element.second<<endl; // for value
    }

     directory.insert(make_pair("damam",87564));

     // declaring iterator
     map<string,int> :: iterator itr;
    
    cout<<"printing by iterator"<<endl;
     for(itr = directory.begin(); itr!=directory.end(); itr++){
            cout<<itr->first<<" -> "<<itr->second<<endl;
     }
     
     // doubt why error here
    //  map<string,int> :: iterator Itr;
    //   cout<<"printing by reverse iterator"<<endl;
    //  for(Itr = directory.rbegin(); Itr != directory.rend(); Itr++){
    //         cout<<Itr->first<<" -> "<<Itr->second<<endl;
    //  }

}