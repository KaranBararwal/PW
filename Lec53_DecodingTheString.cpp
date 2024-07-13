#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
using namespace std;

string DecodedString( string s){
    // time coplexity = O(n) where n is the length of decoded string
    // space compelxity = O(n) where n is the length of decoded string

    //3[b2[ca]]
    string result="";

    //transversing the encoded string
    for(int i=0;i<s.size();i++){

         if(s[i]!=']'){
            result.push_back(s[i]);
            /*it is taking input till ]
            so result = 3[b2[ca
                */
         }
         else{
            
            //extract str from result
            string str = "";

            /*take input till result is get empty(for last case) or it reaches [
                in example it will reach bracket before ca*/
            while(!result.empty() && result.back()!='['){
                 str.push_back(result.back());
                 /*result.back() is used to access the last element of string
                 here when we take the last element of result string 
                 then we remove the last element for next iteration
                 in our example we will first take 'c' and then 'a'
                  */
                 result.pop_back();
            }
            /*we will get the string in reverse order so we need to reverse it for getting right order
             in our example it is 'ac' so will made it 'ca'  */
             //reversing the str

             reverse(str.begin(),str.end());

             // now our result=3b[b2[
                //remove last char from result which is [
                   result.pop_back();

                   //extract num from result=3b[b2
                   string num="";
                   /* take input till result string get empty (for last case) or 
                   it reach to a character value */
                   while(!result.empty() && (result.back()>='0' && result.back()<='9')){
                         num.push_back(result.back());
                         result.pop_back();
                   }

                   // reversing the num string
                   reverse(num.begin(),num.end());

                   // convert string to integer
                   int n = stoi(num);

                   //inserting str in result n times
                   
                   // till n is positive
                   while(n){
                    result+=str;
                    n--;
                   }
         }
    }

    return result;
}

int main(){
    string s;
    cout<<"enter the string ";
    cin>>s;
    
   cout<< DecodedString(s);
}