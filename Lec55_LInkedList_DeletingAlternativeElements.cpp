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

class LinkedList{ // iski property hai ki iske pass head hai for pointing
    public:
    Node *head;

    LinkedList(){
        head = NULL;
    }

    void InsertAtTail(int val){
        
        Node *new_node = new Node(val);
        if(head==NULL){
            head = new_node;
            return;
        }

        Node *temp = head;
        while(temp->next!=NULL){
           temp = temp->next;
        }
        // bilkul end tak aa chuke hai ab uske baad apna element insert kar denge
        temp->next = new_node;
    }

    void display(){
        Node *temp = head;
        while(temp!=NULL){
            cout<<temp->val<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

void deleteAlternativeNodes( Node * &head){

    Node * curr_node = head;
    while(curr_node!=NULL && curr_node->next!=NULL){
        Node * temp = curr_node->next; // this is node to be deleted
        curr_node->next = curr_node->next->next;
        free(temp);
        curr_node = curr_node->next;
    }
}

int main(){

    LinkedList ll;
    int n;
    cout<<"enter the number"<<endl;
    cin>>n;
    for(int i=1;i<=n;i++){
        ll.InsertAtTail(i);
    }
    ll.display();
    deleteAlternativeNodes(ll.head);
    ll.display();
}