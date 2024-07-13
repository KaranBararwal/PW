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

    public:
    Node *head;

    LinkedList(){
        head = NULL;
    }
    
    void insertAtTail(int val){

        Node *new_node = new Node(val);
         if(head==NULL){
            head = new_node;
            return;
        }

        Node *temp = head;

        while(temp->next!=NULL){
            temp = temp->next;
        }
        // now temp is pointing at the last node
        temp->next = new_node;

        // it is by default that (new_node->next = NULL)
       
    }

    void display(){

    Node *temp= head;
    while(temp!=NULL){
        cout<<temp->val<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

// doubt-: why this is showing error
// void RecursivePrint(){

//         if(head == NULL){
//             return;
//         }
//        head = head->next;
//         RecursivePrint();
//         cout<<head->val<<" ";

//     }

};

void RecursivePrint(Node * head){
        if(head == NULL){
            return;
        }

        RecursivePrint(head->next);
        cout<<head->val<<" ";

    }

int main(){
    LinkedList ll;
    int n;
    cout<<"enter the number"<<endl;
    cin>>n;
    for(int i=1;i<=n;i++){
        ll.insertAtTail(i);
    }
    ll.display();

    RecursivePrint(ll.head);


    return 0;
}