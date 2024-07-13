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

class DoublyLinkedList{

    public:
    Node * head;
    Node * tail;

    DoublyLinkedList(){
         head = NULL;
         tail = NULL;
    }

    void InsertionAtHead(int val){ 

        Node * new_node = new Node(val);
        
        if(head==NULL){
            head = new_node;
            tail = new_node;
            return;
        }
       
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
        return;
    }

    
};

void ReverseDLL(Node * &head , Node * &tail){

    Node * curr_ptr = head;

    while(curr_ptr){  // it means curr_ptr till curr_ptr not eqaul to NULL
        Node * next_ptr = curr_ptr->next;

        curr_ptr->next = curr_ptr->prev;
        // don't do it here focus only on  one node  (next_ptr->next = curr_ptr;)

        curr_ptr->prev = next_ptr;  // here we cant write curr_ptr->next cuz it's value changed 

        curr_ptr = next_ptr;
        
    }
    // after completing the loop we need to change head & tail of Node

    Node * new_node = head;
    head = tail;
    tail = new_node;

}

void display(Node * head){

    Node *temp = head;

    while(temp){
        cout<<temp->val<<"<->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){

    DoublyLinkedList dll;
    dll.InsertionAtHead(4);
    dll.InsertionAtHead(3);
    dll.InsertionAtHead(2);
    dll.InsertionAtHead(1);
    display(dll.head);
    ReverseDLL(dll.head , dll.tail);
    display(dll.head);

    return 0;

}