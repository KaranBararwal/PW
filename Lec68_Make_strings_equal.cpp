#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

bool canMakeEqual(vector<string> &v){
    // Time Complexity --> O(n) 
    // here n = number of characters

    // Space Complexity --> O(m)
    // here m is number of unique characters
        unordered_map<char , int> m;

        for(auto str : v){
            for(char c : str){
                m[c]++;
            }
        }

        int n = v.size();

        for(auto ele : m){
            if(ele.second%n!=0){
                return false;
            }
        }
        return true;
}

int main(){
    int n;
    cout<<"enter the number of string "<<endl;
    cin>>n;

    vector<string> v(n);
    cout<<"enter the strings"<<endl;
    for(int i = 0 ; i < n ; i++){
        cin>>v[i];
    }

    if(canMakeEqual(v)){
        cout<<"string can be made equal"<<endl;
    }
    else{
        cout<<"string can't be made equal"<<endl;
    }
    return 0;
}