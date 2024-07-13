#include <iostream>
#include <limits.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Stack
{
    Node *head;
    int capacity;
    int currentSize;

public:
    Stack(int size)
    {
        capacity = size;
        currentSize = 0;
        head = NULL;
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    bool isFull()
    {
        return currentSize == capacity;
    }

    void push(int val)
    {
        if (currentSize == capacity)
        {
            cout << "Overflow" << endl;
            return;
        }
        Node *new_node = new Node(val);
        new_node->next = head;
        head = new_node;
        currentSize++;
    }

    int pop()
    {
        if (head == NULL)
        {
            return INT_MIN;
        }

        Node *new_node = head->next;
        Node *nodeRemoved = head;

        int deletedValue = head->data;
        head->next = NULL;
        delete nodeRemoved;

        head = new_node;
        currentSize--;
        return deletedValue;
    }

    int size()
    {
        return currentSize;
    }

    int getTop()
    {
        return head->data;
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