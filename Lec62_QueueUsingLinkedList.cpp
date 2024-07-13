#include<iostream>
using namespace std;

class Node{
    
    public:
    int data;
    Node * next;
    Node(int val){
        data = val;
    }
};

class Queue{
    
    Node * head;
    Node * tail;
    int size;

    public:

    Queue(){
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void enqueue(int val){
        Node *new_node = new Node(val);
        if(head == NULL){ 
            // Linked List is empty
            head = new_node;
            tail = new_node;
        }
        else{
            tail->next = new_node;
            tail = new_node;
        }
        size++;
    }

    void dequeue(){

        if(head==NULL){
            // Linked List is empty
            cout<<"Underflow"<<endl;
            return;
        }
        else{
            Node *oldHead = head;
            // Node * newHead = head->next;
            // head = newHead;
           head = head->next;
            if( head == NULL ){
                // single Node
                tail = NULL;
                return;
            }
            oldHead->next = NULL;
            delete oldHead;
            size--;
            return;
        }
    }

    int getSize(){
        return size;
    }

    bool isEmpty(){
        return head == NULL;
    }

    int front(){
        if(head == NULL){
            return -1;
        }
        return head->data;
    }

};

int main(){
    Queue qu;
    qu.enqueue(1);
    qu.enqueue(2);
    qu.enqueue(3);
    qu.enqueue(4);
    
    qu.dequeue();
    qu.enqueue(5);

    while(not qu.isEmpty()){
         cout<<qu.front()<<"  "<<qu.getSize()<<endl;
         qu.dequeue();
    }
    return 0;
}