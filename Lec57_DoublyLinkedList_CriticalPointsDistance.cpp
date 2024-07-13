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

bool isCriticalPoint(Node * &currNode){
    if(currNode->prev->val < currNode->val && currNode->next->val < currNode->val){ // local minimum
        return true;
    }
    if(currNode->prev->val > currNode->val && currNode->next->val > currNode->val){ // local maximum
        return true;
    }
    return false;
}

vector<int> CriticalPoints(Node * &head , Node * &tail){
       
       vector <int> ans(2,INT_MAX);

       int firstCP = -1, lastCP = -1;

       Node * currNode = tail->prev; // cuz tail can't be critical point

       if(currNode==NULL){ // single node
        ans[0]=ans[1]=-1;
        return ans;
       } 

       int currPos =0;
       while(currNode->prev!=NULL){
          if(isCriticalPoint(currNode)){

            if(firstCP==-1){
                firstCP = currPos;
                lastCP = currPos;
            }
            else{
                ans[0] = min(ans[0],currPos - lastCP); // min distance
                ans[1] = currPos - firstCP; //max distance
                lastCP = currPos;
            }
          }
          currPos++;
          currNode = currNode->prev;

       }

       if(ans[0]==INT_MAX){
        ans[0]=ans[1]=-1;
       }
       return ans;
}

int main(){

    DoublyLinkedList dll;
    dll.InsertionAtHead(1);
    dll.InsertionAtHead(5);
    dll.InsertionAtHead(2);
    dll.InsertionAtHead(6);
    dll.InsertionAtHead(3);
    display(dll.head);
    vector <int> ans = CriticalPoints(dll.head,dll.tail);
    cout<<"minumum distance b/w critical points "<<ans[0]<<endl<<"maximum distance b/w critical points "<<ans[1]<<endl;
    
    return 0;
    
}
