#include<iostream>
#include<stack>
using namespace std;

bool isValid(string str){ // Time and space complexity = O(n) // worst case sceniro
    stack <char> st;
    for(int i=0;i<str.size();i++){
        char ch = str[i]; // current char

        if(ch=='(' || ch=='[' || ch=='{'){ // opening brackets
            st.push(ch);
        }
        else{ // closing brackets
            
            if(ch==')' && !st.empty() && st.top()=='('){
                st.pop();
            }
            else if(ch==']' && !st.empty() && st.top()=='['){
                st.pop();
            }
            else if(ch=='}' && !st.empty() && st.top()=='{'){
                st.pop();
            }
            else{
                return false;
            }
        }
    }
    return st.empty(); // if it is empty then it is balanced sequence
}

int main(){
    cout<<"Try the other method of dividing string into half"<<endl;

    string st;
    cout<<"enter the brackets sequence "<<endl;
    cin>>st;

    if(isValid(st)==1){
        cout<<"it is a balanced sequence "<<endl;
    }
    else{
       cout<<"it is not a balanced sequence "<<endl;
    }

    return 0;
}