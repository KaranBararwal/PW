#include<iostream>
#include<vector>
#include<limits.h>
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

vector <int> pairSumDLL( Node * &head , Node * &tail, int x){

     vector <int> ans(2,-1);

     while(head!=tail){
            int sum = head->val +tail->val;
        if(sum==x){
            ans[0] = head->val;
            ans[1] = tail->val;
            return ans;
        }

        else if(sum>x) {// now we need to make sum less by moving tail to back
        tail = tail->prev;
     }
       else{   // to make sum more move head to next
            head = head->next;
       }
}
   return ans;
   // Time complexity = O(n)
}

int main(){

    DoublyLinkedList dll;
    dll.InsertionAtHead(4);
    dll.InsertionAtHead(3);
    dll.InsertionAtHead(2);
    dll.InsertionAtHead(1);
    display(dll.head);
     
    vector <int> ans = pairSumDLL(dll.head , dll.tail ,6);
    cout<<ans[0]<<" "<<ans[1];

    return 0;
}