#include<iostream>
#include<stack>
using namespace std;

void reverse(stack <int> &st){
    stack <int> t1,t2;
   
    while(not st.empty()){
        int curr = st.top();
        st.pop();
        t1.push(curr);
    }

    while(not t1.empty()){
        int curr = t1.top();
        t1.pop();
        t2.push(curr);
    }

    while(not t2.empty()){
        int curr = t2.top();
        t2.pop();
        st.push(curr);
    }
}

// Recursive Reverse

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

void recursiveReverse(stack <int> &st){
    // base case
    if(st.empty()){
        return;
    }

    int curr = st.top();
    st.pop();
    recursiveReverse(st);

    // we'll insert every element at the bottom
    insertAtBottom(st , curr);
}

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    
    reverse(st);
       while (not st.empty())
    {
        int curr = st.top();
        st.pop();
        cout << curr << endl;
    }
    
    cout<<"By recursion "<<endl;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    recursiveReverse(st);
       while (not st.empty())
    {
        int curr = st.top();
        st.pop();
        cout << curr << endl;
    }


    return 0;
}