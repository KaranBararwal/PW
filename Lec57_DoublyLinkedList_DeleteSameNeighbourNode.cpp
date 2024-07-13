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

void display(Node * head){

    Node *temp = head;

    while(temp){
        cout<<temp->val<<"<->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void DeleteSameNeighbourNode(Node * &head , Node * &tail){

    Node * currNode = tail->prev; // we don't need to check for last node so we are starting with second last node

    while(currNode!=head){ // also no need to check for head
          // we need two pointers here for checking neighbours
          Node * prevNode = currNode->prev;
          Node * nextNode = currNode->next;

          if(prevNode->val==nextNode->val){
            //we need to delete the current node
            prevNode->next = nextNode;
            nextNode->prev = prevNode;
            free(currNode);
          }
          
          // don't write currNode = nextNode;
          currNode = prevNode;

    }

}

int main(){

    DoublyLinkedList dll;
    dll.InsertionAtHead(1);
    dll.InsertionAtHead(2);
    dll.InsertionAtHead(1);
    dll.InsertionAtHead(1);
    dll.InsertionAtHead(2);
    display(dll.head);
    DeleteSameNeighbourNode(dll.head,dll.tail);
     display(dll.head);
}

