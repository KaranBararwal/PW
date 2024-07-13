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

void PostOrderTraversal(Node * root){
    if(root == NULL){
        return ;
    }

    // for each loop
    for(Node * child : root->children){
        PostOrderTraversal(child);
}
    
    cout<<root->data<<"  ";
    return;
}

int main(){

    Node * root = new Node('A');
    root->children.push_back(new Node ('B'));
    root->children.push_back(new Node('C'));
    root->children.push_back(new Node ('D'));
    root->children[0]->children.push_back(new Node('E'));
    root->children[0]->children.push_back(new Node('F'));
    root->children[2]->children.push_back(new Node('G'));
    PostOrderTraversal(root);

    return 0;
}

//          A
//     B   C      D
//    E F        G