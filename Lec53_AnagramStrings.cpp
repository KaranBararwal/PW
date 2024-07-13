#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool IsAnagram(string s1,string s2){
    // checking the lengths are same or not
    if(s1.length()!=s2.length()){
        return false;
    }
    
    vector<int> freq(26,0);

    for(int i=0;i<s1.length();i++){
        
        freq[s1[i]-'a']++;// for s1 we are incrementing the value of freq
        freq[s2[i]-'a']--;// for s2 we are decrementing the value of freq

    }
    for(int i=0;i<26;i++){
        if(freq[i]!=0){
            return false;
            break;
        }
    }
    return true;
}

int main(){
    string s1,s2;
    cin>>s1>>s2;

    if(IsAnagram(s1,s2)){
        cout<<"strings are anagram";
    }
    else{
        cout<<"strings are not anagram";
    }
}