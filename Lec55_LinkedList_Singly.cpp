#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node *next;

    Node(int data){
        val = data;
        next = NULL;
    }
};

class LinkedList{
    public :
    Node *head;

    LinkedList(){
        head = NULL;
    }
};

int main(){
   
     Node *new_node = new Node(1);
     

    LinkedList ll;
    ll.head = new_node;
    cout<<ll.head->val<<endl;

    return 0; 
}