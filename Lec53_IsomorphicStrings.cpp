#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool IsIsomorphic(string s1, string s2){
    if(s1.size()!=s2.size()){ // checking the lengths are same
        return false;
    }

    vector <int> v1(128,-1);
    vector <int> v2(128,-1);

    for(int i=0;i<s1.length();i++){
        if(v1[s1[i]]!=v2[s2[i]]){ // checking that value in both vector are same for index equal to value of string element at ith index
            return false;
        }
        else{
            v1[s1[i]]=v2[s2[i]]=i; // if value are equal than store same value (i) in both vector at that index(ASCII)
        }
    }
}

int main(){
    string s1,s2;
    cin>>s1>>s2;

     if(IsIsomorphic(s1,s2)){
        cout<<"strings are isomorphic";
    }
    else{
        cout<<"strings are not isomorphic";
    }
}