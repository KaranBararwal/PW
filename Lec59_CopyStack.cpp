#include <iostream>
#include <stack>
using namespace std;

stack<int> CopyStack(stack<int> &input)
{
    stack<int> temp;
    while (input.empty() == 0)
    {                           // jab tak empty nhi hoti
        int curr = input.top(); // [1,2,3]  curr = 3  ,   [1,2]  curr = 3
        input.pop();            //  [1,2]                ,    [1]
        temp.push(curr);        // [1]                      ,    [1,2]
    }

    stack<int> result;
    while (not temp.empty())
    {
        int curr = temp.top();
        temp.pop();
        result.push(curr);
    }

    return result;
}

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    stack<int> res = CopyStack(st);
    while (not res.empty())
    {
        int curr = res.top();
        res.pop();
        cout << curr << endl;
    }

    return 0;
}