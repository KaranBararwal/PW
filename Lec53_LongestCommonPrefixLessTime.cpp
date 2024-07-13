#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
using namespace std;

string LongestCommonPrefix( vector<string> &str){
    // keeping first string as const and compairing it with all other strings
     string s1=str[0];
     string ans="";
     int ans_length=0;
     int i=0;
     int j=0;
     // we can also use for loop here
     while(i<s1.size() && j<str[i].size() && s1[i]==str[i][j]){
        ans_length++;
         i++;
         j++;
     }
     return s1.substr(0,ans_length);
}

int main(){
    int n;
    cout<<"enter the number of strings ";
    cin>>n;
    
    cout<<"enter strings";
    vector <string> str(n);
    for(int i=0;i<n;i++){
        cin>>str[i];
    }
    
    cout<<"longest common prefix :"<<LongestCommonPrefix(str)<<endl;
    return 0;
}