#include<iostream>
#include<stack>
using namespace std;

void CopyStackRecursive( stack <int> &input , stack <int> &result){  // pass by reference to insert value in actual stack
    // base case
    if(input.empty()==1){
        return ;
    }

    int curr = input.top();
    input.pop();

    CopyStackRecursive(input,result); // we will assume that it has copied the rest of array correctly
    result.push(curr); // and we'll push the top element on that stack
}

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    stack<int> res ;
    CopyStackRecursive(st,res);
    while (not res.empty())
    {
        int curr = res.top();
        res.pop();
        cout << curr << endl;
    }

    return 0;
}