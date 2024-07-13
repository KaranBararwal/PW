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
        // now temp is pointing at last node so
        temp->next = new_node;
        new_node->next = NULL;
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

    Node *reverseLL(Node * &head){
         Node * prev_ptr = NULL;
         Node * curr_ptr = head;

         while(curr_ptr!=NULL){ // when currptr reaches NULL whole LinkedList will get reversed
             Node *next_ptr = curr_ptr->next; // we need to store address of next link otherwise we'll lost connection of linkedList
             curr_ptr->next = prev_ptr;

             // we cant't do prevptr++; &  currptr++;

             prev_ptr = curr_ptr;
             curr_ptr = next_ptr;

         }
         // now we just need to change the head of LinkedList

         Node * new_head = prev_ptr; // cuz prev_ptr is pointing at the last node 
         return new_head;
    }

    Node *reverseLLRecursion(Node * &head){
       // cout<<"Hi"<<endl;
        // base case
        if(head == NULL || head->next == NULL){
          //  cout<<"Yes";
            return head;
        }
        
        // recursive case
        Node *new_head = reverseLLRecursion(head->next);

        // try to dry run it whenever u see it 

        head->next->next = head;
       // cout<<"Ok";
        head->next = NULL; //head is now pointing to the last node in reversed ll

        return new_head;
    }

// important
Node * reversekLL(Node * & head , int k){

    Node * prev_ptr = NULL;
    Node * curr_ptr = head;

    int counter = 0; // for counting first k Nodes

    // reversing first k nodes
    while(curr_ptr!=NULL && counter<k){
        Node * next_ptr = curr_ptr->next;
        curr_ptr->next = prev_ptr;
        prev_ptr = curr_ptr;
        curr_ptr = next_ptr;
        counter++;
    }

    // now curr_ptr will give us (k+1)th node

    if(curr_ptr!=NULL){
        Node * new_head = reversekLL(curr_ptr,k);//recursive call
        head->next = new_head;
    }

    return prev_ptr; // prev_ptr will give the new_head of connected linkedList
}



int main(){

    LinkedList ll;
    int n;
    cout<<"enter the number "<<endl;
    cin>>n;

    for(int i=0;i<n;i++){
        ll.insertAtTail(i);
    }

    ll.display();
    ll.head = reverseLL(ll.head);
    ll.display();
    
    ll.head = reverseLLRecursion(ll.head);
    ll.display();

    ll.head = reversekLL(ll.head,2);
    ll.display();
    
    return 0;
}