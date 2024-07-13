#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node * prev;
    Node * next;

    Node(int data){
       val = data;
       prev = NULL;
       next = NULL;
    }

};

class doublyLinkedList{
       public :
       Node * head;
       Node * tail; // we can access tail by head but it is easy to access the linkedList from tail by this pointer
       
       doublyLinkedList(){
        head = NULL ;
        tail = NULL ;
       }
};

int main(){
    int n;
    cout<<"enter the value "<<endl;
    cin>>n;

    Node *new_node = new Node(n);

    doublyLinkedList dll;
    dll.head = new_node;
    cout<<dll.head->val<<endl;
    return 0;
}