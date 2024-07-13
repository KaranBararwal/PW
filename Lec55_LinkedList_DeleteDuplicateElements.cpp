#include<iostream>
using namespace std;

class Node{
    
    public :
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
        head = NULL ;
     }

     void InsertAtTail( int val){
         
        Node *new_node = new Node(val); 
        if(head==NULL){
            head = new_node;
            return;
        }

        Node *temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
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

void deleteDuplicateNode(Node * &head){
    Node *curr_node = head;
    while(curr_node){ // that means (curr_node!=NULL)

      // dont't write like that  while((curr_node->val == curr_node->next->val) && curr_node->next!=NULL){
        
           while( curr_node->next!=NULL && (curr_node->val == curr_node->next->val)){
            // delete curr->next
            Node* temp = curr_node->next; // node to be deleted
            curr_node->next = curr_node->next->next;
            free(temp);
           
        }
        //this loop ends when current node and next node values are different
        // or linkedlist ends
        curr_node = curr_node->next;
        
    }
    // Time coplexity O(n)
}

int main(){
    LinkedList ll;
    int n;
    cout<<"enter the number "<<endl;
    cin>>n;
    for(int i=1;i<=n;i++){
        ll.InsertAtTail(i);
        if(i>=2 && i<=n-2){
            ll.InsertAtTail(i);
        }
    }
    ll.display();
    deleteDuplicateNode(ll.head);
    ll.display();
    return 0;

}