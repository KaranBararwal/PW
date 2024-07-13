#include <iostream>
#include <limits.h>
using namespace std;

// we can remove this word from whole code
class Stack
{
    int capacity;
    int top;
    int *arr;

public:
    Stack(int c)
    {
        this->capacity = c;
        arr = new int[c];
        this->top = -1;
    }

    void push(int data)
    {
        if (this->top == this->capacity - 1)
        {
            cout << "Overflow" << endl;
            return;
        }

        this->top++;
        this->arr[this->top] = data;
    }

    void pop()
    {
        if (this->top == -1)
        {
            cout << "Underflow" << endl;
            return;
        }

        this->top--; // no need to directly delete whenever we decrement the top it will replace that garbage value
    }

    int getTop()
    {
        if (this->top == -1)
        {
            cout << "Underflow" << endl;
            return INT_MIN;
        }

        return this->arr[this->top];
    }

    bool isEmpty()
    {

        return this->top == -1;
    }

    int currentSize()
    {

        return this->top + 1;
    }

    bool isFull()
    {
        return this->top == this->capacity - 1;
    }
};

int main()
{
    int n;
    cout << "enter the size of stack " << endl;
    cin >> n;
    Stack st(n);

    st.push(1);
    st.push(2);
    st.push(3);
    cout << st.getTop() << endl;
    st.push(4);
    st.push(5);
    cout << st.getTop() << endl;
    st.push(6);

    st.pop();
    st.pop();
    cout << st.getTop() << endl;

    return 0;
}