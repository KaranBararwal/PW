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


bool Ispalindrome(Node * head , Node * tail){  // we are not passing here by reference cuz we don't want to change the value of head and tail of LinkedList
     
    while(head!=tail && head->prev!=tail){   //for odd and even number of nodes
         if(head->val!=tail->val){
            return false;
         }
         head = head->next;
         tail = tail->prev;

    }
    return true;

}


int main(){

    DoublyLinkedList dll;
    dll.InsertionAtHead(1);
    dll.InsertionAtHead(2);
    dll.InsertionAtHead(3);
     dll.InsertionAtHead(4);
    dll.InsertionAtHead(3);
    dll.InsertionAtHead(2);
    dll.InsertionAtHead(1);
    if(Ispalindrome(dll.head,dll.tail)==1){
        cout<<"the linked list is palindrome "<<endl;
    }
    else{
        cout<<"the linked list is not palindrome "<<endl;
    }

}

