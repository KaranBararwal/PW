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

class CircularLinkedList{

    public:
    Node * head;

    CircularLinkedList(){
        head = NULL;
    }

    void InsertAtHead(int val){  // Time copmlexity = O(n)

        Node * new_node = new Node(val);

        if(head==NULL){
            head = new_node;
            new_node->next = head;
            return;
        }

        Node * tail = head;
        
        while(tail->next!=head){
            tail = tail->next;
        }
       
        // now tail is at last node

        tail->next = new_node;
        new_node->next = head;
        head = new_node;
    }

    void InsertAtEnd(int val){  // Time copmlexity = O(n)

        Node *new_node = new Node(val);

        if(head==NULL){ // empty linked list
            head = new_node;
            new_node->next = new_node;
            return ;
        } 

        Node *tail = head;

        while(tail->next!=head){
            tail = tail->next;
        }

        // now tail pointer is pointing to the last node

        // inserting
        tail->next = new_node;
        new_node->next = head;
        tail = new_node;
        return ;
    }

    void deleteAtStart(){   // Time copmlexity = O(n)

        if(head==NULL){
            return;
        }

        Node * temp = head;
        Node * tail = head;

        while(tail->next!=head){
            tail = tail->next;
        }

        // now tail is pointing at the last node

        head = head->next; // move head to next node
        tail->next = head; // point next node of tail to new head
        free(temp);        // free the previous head i.e. temp 
        
        return;
    }
   
    void deleteAtEnd(){     // Time copmlexity = O(n)

        if(head==NULL){
            return;
        }

        Node * tail = head;

        while(tail->next->next!=head){
            tail = tail->next;
        }

        // now tail is pointing to second last node

        Node *temp = tail->next; // pointing the end node which we want to delete
        tail->next = head;  // second last node should point to head
        free(temp);

        return ;
    }

        void display(){

        Node *temp = head;

        do{
           cout<<temp->val<<"->";
           temp=temp->next;
        } while(temp!=head);
        cout<<endl;
    }

       void printCircular(){
   
   int n;
   cout<<"enter number of node to be printed "<<endl;
   cin>>n;
    Node *temp = head;
    for(int i=0;i<n;i++){
        cout<<temp->val<<"->";
        temp = temp->next;
        }
   }

};

int main(){
    CircularLinkedList cll;
    cll.InsertAtHead(3);
    cll.InsertAtHead(2);
    cll.InsertAtHead(1);
    cll.InsertAtEnd(4);
    cll.InsertAtEnd(5);
    cll.InsertAtEnd(6);
    cll.display();
    cll.deleteAtStart();
    cll.deleteAtStart();
     cll.display();
     cll.deleteAtEnd();
     cll.deleteAtEnd();
     cll.display();
   // cll.printCircular();
}