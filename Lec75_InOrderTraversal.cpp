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

void InOrderTraversal(Node * root){

    if(root == NULL){
        return;
    }

    int childNodes = root->children.size();
    // we'll call recursively inOrder traversal for all the nodes expect the last nodes

    for(int i = 0 ; i< childNodes - 1 ; i++){
        InOrderTraversal(root->children[i]);
    }
    
    cout<<root->data<<"  ";
    
    //last node
    if(childNodes > 0){
          InOrderTraversal(root->children[childNodes-1]);
    }
}


int main(){

    Node * root = new Node('A');
    root->children.push_back(new Node ('B'));
    root->children.push_back(new Node('C'));
    root->children.push_back(new Node ('D'));
    root->children[0]->children.push_back(new Node('E'));
    root->children[0]->children.push_back(new Node('F'));
    root->children[2]->children.push_back(new Node('G'));
    InOrderTraversal(root);

    return 0;
}

//          A
//     B   C      D
//    E F        G