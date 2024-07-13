#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
using namespace std;

int  LongestString( string str, int k){
    // doubt in code written in //

    // Time complexity -> 0(n) where n is the length of input string
    // space comlexity -> O(1)
    int s=0;
    int e=0;
     int zero_count=0;
     int max_length=0;

    // string result="";
    while(e<=str.length()){

       if(str[e]=='0'){
         zero_count++;
       }

       while(zero_count>k){

        if(str[s]=='0'){
            zero_count--;
        }
         s++; // contracting the window
       }
      
       //zero_count<=k;
      // result=(str[s],str[e]);
      // max_length=result.size();
        max_length=max(max_length,e-s+1);
       e++;
       
    }
   
    return max_length;
}

int main(){
    string str;
    cout<<"enter binary string";
    cin>>str;

    int k;
    cout<<"enter maximum flips of 0s";
    cin>>k;

    cout<<LongestString(str,k);
}