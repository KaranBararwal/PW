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

Node * LowestCommonAncestor( Node * root , Node * node1 , Node * node2){

    // if both the values are less than root node value then LCA will be at left subtree

    if( root->value > node1->value && root->value > node2->value){
           return LowestCommonAncestor(root->left , node1 , node2);
    }
    
    // if both the values are greater than root node value then LCA will be at right subtree

    if( root->value < node1->value && root->value < node2->value){
        return LowestCommonAncestor(root->right , node1 , node2);
    }

    // if root value is in middle of the nodes values or equal to root value then
    return root;

}

int main(){

    BST bst;

    InsertionBST(bst.root , 3);
    InsertionBST(bst.root , 1);
    InsertionBST(bst.root , 4);
    InsertionBST(bst.root , 6);
    InsertionBST(bst.root , 2);
    
     Node * node1 = new Node(2);
     Node * node2 = new Node(1);

    cout<<"LCA is "<<(LowestCommonAncestor(bst.root , node1, node2))->value;
      return 0;
}

//     3
//  1     4
//    2     6