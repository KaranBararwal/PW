 // LeetCode --> 205
#include<iostream>
#include<unordered_map>
using namespace std;

bool checkOne2OneMapping(string s1 , string s2){
    unordered_map<char,char> m;

    for(int i = 0 ; i < s1.length() ; i++){
        if(m.find(s1[i]) != m.end()){
            if(m[s1[i]] != s2[i]){
                return false;
            }
        }
        else{
            m[s1[i]] = s2[i];
        }
    }
    for(auto ele : m){
        cout<<ele.first << " is paired with "<<ele.second<<endl;
    }
    return true;
}

bool isIsomorphic(string s, string t) {
    // Time Complexity --> O(N)
    // here N is the sum of length of both the strings

    // Space Complexity --> O(n)
    // here n is the number of unique character in both strings
    if(s.length()!=t.length()){
        return false;
    }
    // checking mapping from s to t
    bool st = checkOne2OneMapping(s,t);
    // checking mapping from t to s
    bool ts = checkOne2OneMapping(t,s);
    if(st){
        cout<<"first is mapped with second"<<endl;
    }
    else{
        cout<<"first is not mapped with second"<<endl;
    }

    if(ts){
        cout<<"second is mapped with first"<<endl;
    }
    else{
        cout<<"second is not mapped with first"<<endl;
    }
    return (st && ts);
}

int main(){
    string t,s;
    cout<<"enter two strings "<<endl;
    cin>>t>>s;

    cout << (isIsomorphic(t,s) ? "Isomorphic" : "Not Isomorphic")<<endl;
    return 0;
}