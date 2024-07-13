#include<iostream>
using namespace std;

template <typename T>
// template class
class Node{

    public:
    T val;
    Node *next;

    Node(T data){
        val = data;
        next = NULL;
    }
};

int main(){
    // declartion

    Node <int> *node1 = new Node <int> (3);
    cout<<node1->val<<endl;

    Node <char> *node2 = new Node <char> ('k');
    cout<<node2->val<<endl;
}