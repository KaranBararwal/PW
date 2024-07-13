#include<iostream>
#include <algorithm> // for transform() function
#include<set>
using namespace std;

bool checkAllAlphabets(string s){
    if(s.length()<26){
      return false;
    }

    //important function
    transform(s.begin(),s.end(),s.begin(),::tolower);

    set <char> alphabets;
    for(auto ch:s){
        alphabets.insert(ch);
    }

    return alphabets.size()==26; // size() for sets
}

int main(){
    string s;
    cout<<"enter string "<<endl;
    cin>>s;
    
    if(checkAllAlphabets(s)==1){
        cout<<"It contains all alphabets "<<endl;
    }
    else{ // it also contain the condition where string length is greater than 26 but doesn't contain all alphabets
        cout<<"It doesn't contains all alphabets "<<endl;
    }

}