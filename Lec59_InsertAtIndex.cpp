#include<iostream>
#include<stack>
using namespace std;

void insertAtIdx( stack <int> &input , int idx , int val){
    stack <int> temp;
    int n = input.size();
    int current = 0;
    while( current < n - idx){ 
         current++;
         int curr = input.top();
         input.pop();
         temp.push(curr);
    }
      // now we have reached at the desired index
    input.push(val);

    // now we'll insert all the elements again 

    while(not temp.empty()){
        int curr = temp.top();
        temp.pop();
        input.push(curr);
    }
}

int main(){
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(40);
    st.push(50);
    
    // indexing start from the bottom and from 0

    insertAtIdx(st,2,30);
    
      while (not st.empty())
    {
        int curr = st.top();
        st.pop();
        cout << curr << endl;
    }
    return 0;
}