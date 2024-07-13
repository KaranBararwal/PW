#include<iostream>
#include<vector>
#include<string>
using namespace std;

string SortString(string str){
    vector <int> freq(26,0);
    //filling the frequency of characters 
    for(int i=0;i<str.length();i++){
        int index=str[i]-'a';
        freq[index]++;
    }
    
    // sorting the string
    int j=0;
    for(int i=0;i<26;i++){
        while(freq[i]--){
            str[j++]=i+'a';
        }
    }
    return str;
}
int main(){
    string str;
    cin>>str;
    //by count sort
   cout<< SortString(str);
}