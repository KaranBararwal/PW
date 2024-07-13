#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack <int> &input , int val){
    // Time & Space Complexity = O(n)
    stack <int> temp;

    while(not input.empty()){
        int curr = input.top();
        input.pop();
        temp.push(curr);
    }

    input.push(val); // here we inserting at the bottom

    while(not temp.empty()){
        int curr = temp.top();
        temp.pop();
        input.push(curr);
    }
    return;
}

void insertAtBottomRecursive(stack <int> &input , int val){
    // base case
    if(input.empty()==1){  // when stack is empty we'll insert the value at bottom
        input.push(val);
        return ;
    }

    int curr = input.top();
    input.pop();
    insertAtBottomRecursive(input,val);
    input.push(curr);
    return;
}

int main(){
    stack <int> st;
    st.push(2);
    st.push(3);
    st.push(4);
    insertAtBottom(st,1);
    insertAtBottomRecursive(st,0);

    while(not st.empty()){
        int curr = st.top();
        st.pop();
        cout<<curr<<endl;
    }
    return 0;
}