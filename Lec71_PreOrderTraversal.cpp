#include<iostream>
using namespace std;

class Node{
     
     public:
     int value;
     Node * left;
     Node * right;

     Node(int data){
        value = data;
        left = NULL;
        right = NULL;
     }
};

void preOrderTraversal(Node * rootNode){
    // base case
    if(rootNode == NULL){
        return;
    }

    cout<<rootNode->value<<" ";

    //recursive case
    preOrderTraversal(rootNode->left);
    preOrderTraversal(rootNode->right);
}

int main(){
   /*                                 1
                            2                    3
                        4       5           6         7
       */       

      Node * root = new Node(1);
      root->left = new Node(2);
      root->right = new Node(3);
      root->left->left = new Node(4);
      root->left->right  = new Node(5);
      root->right->left = new Node(6);
      root->right->right = new Node(7);

      preOrderTraversal(root);
      return 0;            

}