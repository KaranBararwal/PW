 // LeetCode --> 242
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

bool isAnagram(string s, string t) {
    // Time Complexity --> O(N)
    // here N is the sum of lenght of both the strings

    // Space Complexity --> O(n)
    // here n is the number of unique character in both strings
    if(s.size()!=t.size()){
        return false;
    }

    unordered_map<char,int> m;

    for(auto c1 : s){
        m[c1]++;
    }

    for(auto c2 : t){
        if(m.find(c2)==m.end()){
            return false;
        }
        else{
            m[c2]--;
        }
    }
    for(auto ele : m){
        if(ele.second!=0){
            return false;
        }
    }
    return true;
}

int main(){
    // int n;
    // cout<<"enter the number of string "<<endl;
    // cin>>n;

    vector<string> v(2);
    cout<<"enter two strings"<<endl;
    for(int i = 0 ; i < 2 ; i++){
        cin>>v[i];
    }

    if(isAnagram(v[0],v[1])){
        cout<<"string are anagram"<<endl;
    }
    else{
        cout<<"string aren't anagram"<<endl;
    }
    return 0;
}