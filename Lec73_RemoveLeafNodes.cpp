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

class BST{  // it will create a empty BST
    public:
    Node * root;

    BST(){
        root = NULL;
    }

};

void InsertionBST(Node * &root , int val){  // here pass by reference otherwise it will don't get updated
         
         Node * newNode = new Node(val);
         // if the BST is empty
         if(root == NULL){
            root = newNode; 
            return;
         }

         Node * current = root;

         while(true){

            if(current->value > val) { // it means root node value is greater then given value
            // so we'll insert the value at left subtree of root
            
            // if left child of current root node doesn't exist so we'll insert value there
                 if(current->left == NULL){
                    current->left = newNode;
                    return;
                 }
                 // if left child of the current root exist then we need to check for that node
                 // so we'll make that node current node
                 current = current->left;
            }

            else{  // current->value < val
            // it means root node value is less then given value
            // so we'll insert the value at right subtree of root node

            // if right child of current root doesn't exist so we'll insert value there
                if(current->right == NULL){
                    current->right = newNode;
                    return;
                }
                
                 // if right child of the current root exist then we need to check for that node
                 // so we'll make that node current node
                 current = current->right;
            }

         }        
}

Node * removeLeafNodes(Node * root){

    // base case
    // if the BST is empty
    if(root == NULL){
        return root;
    }

    // if it is leaf node

    if(root->left == NULL && root->right == NULL){
        return NULL; // it will make root->left or root->right equal to NULL
    }

    // recursive case
    root->left = removeLeafNodes(root->left); // left subtree is equal to the subtree after removing all leaf nodes from left subTree

    root->right = removeLeafNodes(root->right); // right subtree is eqaul to the subtree after removing all leaf nodes from right subTree

    return root;
}

void preOrderTraversal(Node * root){
    // base case
    if(root == NULL){
        return;
    }

    // recursive case
    cout<<root->value<<"  ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

int main(){

    BST bst;

    InsertionBST(bst.root , 3);
    InsertionBST(bst.root , 1);
    InsertionBST(bst.root , 4);
    InsertionBST(bst.root , 6);
    InsertionBST(bst.root , 2);
    
    preOrderTraversal(bst.root);
    cout<<endl;

    removeLeafNodes(bst.root);
    preOrderTraversal(bst.root);
    cout<<endl;    
      return 0;
}

//     3
//  1     4
//    2     6