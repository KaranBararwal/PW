#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout << st.top() << endl;
    st.push(4);
    st.push(5);
    cout << st.top() << endl;
    st.push(6);

    st.pop();
    st.pop();
    cout << st.top() << endl;
    if (st.empty() == 0)
    { // it mean that condition (st.empty) is false
        cout << "stack is not empty " << endl;
    }
    else
    {
        cout << "stack is empty " << endl;
    }
}