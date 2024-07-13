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
        
        // it is important to add this condition
        if(head==NULL){ // empty linked list
            head = new_node;
            tail = new_node;
            return ;
        }

        new_node->next = head;
        head->prev = new_node;
        head = new_node;
        return ;
    }

   void InsertionAtTail(int val){
        
        Node * new_node = new Node(val);

        if(tail==NULL){
            head = new_node;
            tail = new_node;
            return ;
        }

        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;   
        return ;
   }

   void InsertionAtPosition(int val , int pos){
       
       // we are assuming that pos is less than linkedList size
       Node * new_node = new Node(val);

       Node * temp = head;
       int counter = 1; // pointing at first node

       while(counter < (pos-1)){
           temp = temp->next;
           counter++;
       }

       // now temp will be pointing at (k-1)th node cuz loop runs for (k-2)
       // and temp = temp->next (it means it points (k-1)th node)
     
     // we should not points temp to new_node first otherwise we'll loss connection to the LinkedList

       new_node->next = temp->next;
       temp->next = new_node;

       new_node->next->prev = new_node;
       new_node->prev = temp;
       return ;
   }

    void DeletionAtStart(){

        Node * temp = head;

        if(head==NULL){ // doubly linked list is empty
           return ;
        }

        head = head->next;

        if(head==NULL){ // doubly linked list have only one node
            tail = NULL;
        }
        else{
            head->prev = NULL;
        }

        free(temp);
        return;
    }

    void DeletionAtEnd(){

        if(head == NULL){  // doubly linked list is empty
            return ;
        }

        Node * temp = tail;

        tail = tail->prev;

        if(tail==NULL){  // doubly linked list have only one node
            head = NULL;
        }
        else{
            tail->next = NULL;
        }

        free(temp);
    }
     
     void DeletionAtPosition(int pos){
           // we are assuming that pos value is less than or equal to the size of linkedList

           if(head==NULL){ // empty linkedList
            return;
           }

           Node *temp = head ;
           int counter = 1;

           while(counter < pos){
            temp = temp->next;
            counter++;
           }

           // now temp is pointing at the Kth position

           //logic
           temp->prev->next = temp->next;
           temp->next->prev = temp->prev;
           free(temp);
           return;
     }
};

  void display( Node * head){

        Node * temp = head;

        while(temp!=NULL){
            cout<<temp->val<<"<->";
            temp = temp->next;
        }cout<<endl; 
        // last node points to NULL but NULL not points to last Node
    }

int main(){
    
   DoublyLinkedList dll;
   dll.InsertionAtHead(3);
   dll.InsertionAtHead(2);
   dll.InsertionAtHead(1);
   display(dll.head);
   dll.InsertionAtTail(4);
   dll.InsertionAtTail(5);
   dll.InsertionAtTail(6);
   display(dll.head);
   dll.InsertionAtPosition(69,4);
   display(dll.head);
   dll.DeletionAtStart();
   display(dll.head);
   dll.DeletionAtStart();
   display(dll.head);
   dll.DeletionAtEnd();
   display(dll.head);
    dll.DeletionAtEnd();
   display(dll.head);
   dll.InsertionAtHead(2);
   display(dll.head);
   dll.DeletionAtPosition(2);
   display(dll.head);

   return 0;
}