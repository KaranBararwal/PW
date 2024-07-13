#include<iostream>
#include<vector>
using namespace std;

class Node {
   public:

   char data;
   vector <Node*> children; // storing addresses of all the children

   Node(char data){
    this->data = data;
   }
};
void preOrderTraversal(Node * root){
    if(root == NULL){
        return ;
    }

    cout<<root->data<<"  ";
    for(Node * child : root->children){
        preOrderTraversal(child);
    }
    return;
}

int main(){
    Node * root = new Node('A');
    root->children.push_back(new Node('B'));
    root->children.push_back(new Node('C'));
    
    cout<<root->data<<endl;
    cout<<"children of A : ";
   for(Node * child : root->children){
         cout<<child->data<<"  ";
   }
    return 0;
    
}