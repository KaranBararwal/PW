#include<iostream>
using namespace std;

class Node{

     public:
   
    int val;
    Node * next; // because this pointer is pointing to another node 

    Node(int data){
        val=data;
        next=NULL;
    }
};

void InsertAtHead(Node * &head, int val){ // pass by reference cuz we want to change value in linked list
     Node *new_node = new Node(val);
     new_node->next = head;
     head = new_node;
     // Time coplexity = O(1)
}

void InsertAtTail(Node * &head, int val){
  
    Node *new_node = new Node(val);

    Node *temp=head;
    while(temp->next!=NULL){
         temp=temp->next;
    }
    // temp has reached last node
    temp->next=new_node;
    // Time complexity = O(n)
    // If tail pointer is given then O(1)
}

void InsertAtPosition(Node * &head , int val , int pos){
    
    if(pos==0){
        InsertAtHead(head,val);
        return;
    }
    
    Node *new_node = new Node(val);
    Node *temp = head;
    int current_pos = 0;
    while(current_pos!=pos-1){
        temp=temp->next;
        current_pos++;
    }

   // temp is pointing to node at (pos-1)
   // very important
   new_node->next = temp->next; // new node pointing to node at postion
   temp->next = new_node;  // (pos-1) node pointing to new node
   
   // Time Complexity O(pos) in worst case O(n)
}

void UpdateAtPosition( Node * &head , int val , int pos){
    
    Node * temp = head;
    int current_position = 0 ;

    while(current_position!=pos){
        temp = temp->next;
        current_position ++;

    }
    // temp will be pointing to the position
    temp->val = val;
     // Time Complexity O(pos) in worst case O(n)
}

void deleteAtHead( Node* &head){
   // Time Complexity O(1)
    Node *temp = head;
    head = head->next;
    free(temp);
}

void deleteAtTail( Node * &head){

    Node *second_last = head;

    while(second_last->next->next!=NULL){
        second_last = second_last->next;
    }
    
    // now second_last will be pointing to second last node
    Node *temp = second_last->next; // node to be deleted
    second_last->next=NULL; 
    free(temp);
    // Time Complexity O(n) either tail node is given or not cuz tail node can't go back
}

void deleteAtPosition( Node * & head , int pos){

    if(pos==0){
        deleteAtHead(head);
        return ;
    }
    int curr_pos = 0;
    Node * prev = head;
    while(curr_pos!=pos-1){
       prev = prev->next;
       curr_pos++;
    }

    // prev is pointing to node at pos-1
    Node *temp = prev->next; // node to be deleted
    prev->next = prev->next->next;
    free(temp);

    // Time complexity in worst case O(n)

}

void display(Node *head){

    Node *temp= head;
    while(temp!=NULL){
        cout<<temp->val<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    /* declartion
    Node *n = new Node(1);
    cout<<n->val<<" "<<n->next<<endl; 
    */
    Node * head = NULL;
    InsertAtHead(head,2);
    display(head);
    InsertAtHead(head ,1);
    display(head);
    InsertAtTail(head,3);
    display(head);
    InsertAtPosition(head,4,1);
    display(head);
    UpdateAtPosition(head,5,2);
    display(head);
    deleteAtHead(head);
    display(head);
    deleteAtTail(head);
    display(head); 
    deleteAtPosition(head,1);
    display(head);
    return 0;
}