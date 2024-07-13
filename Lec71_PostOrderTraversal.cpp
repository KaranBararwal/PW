#include<iostream>
using namespace std;

class Node{
    public:
    int value;
    Node * left;
    Node * right;

    Node(int data){
        value = data;
        left = right = NULL;
    }
};

void PostOrderTraversal(Node * rootNode){
    // base case
    if(rootNode==NULL){
        return;
    }

    //recursive case
    PostOrderTraversal(rootNode->left);
    PostOrderTraversal(rootNode->right);
    cout<<rootNode->value<<"  ";
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

      PostOrderTraversal(root);
      return 0;            

}