#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
using namespace std;

string LongestCommonPrefix(vector <string> &str){
       
       //sorting the array of strings
       sort(str.begin(),str.end());
      

       string s1=str[0]; // first string 
       int i=0;
       string s2=str[str.size()-1]; // last string
       int j=0;

       string ans="";
       
       // the elements which are common is first and last string in sorted strings are common in all strings
        while(i<s1.size() && j<s2.size()){
            if(s1[i]==s2[j]){
                ans+=s1[i]; // if we write ans=s1[i] then it will give last common prefix
                i++;
                j++;
            }
            else{
                break;
            }
       }
       return ans;

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
}