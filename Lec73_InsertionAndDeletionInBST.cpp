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

Node * insertBSTrecursive(Node * root , int val){

    // base case
    if(root == NULL){
        Node * newNode = new Node(val);
        return newNode;
    }

    // recursive case

    if(root->value > val){  // insertion will be at left subtree
        root->left = insertBSTrecursive(root->left , val);
    }
    else if(root->value < val){  // insertion will be at right subtree
        root->right = insertBSTrecursive(root->right , val);
    }

    return root;
}

// searching

bool searchBSTrecursive(Node * root , int key){
    
    // base case
    if(root == NULL){
        return false;
    }

    if(root->value == key){
        return true;
    }
    // recursive case
    if(root->value < key){  // so the value will be at right subtree
         return searchBSTrecursive(root->right , key);
    }
    else if(root->value > key){  // so the value will be at left subtree
         return searchBSTrecursive(root->left , key);
    }
}

Node * largestNodeBST(Node * root){
    
    // finding the right most value of left SubTree
    Node * curr = root;
    while(curr && curr->right){ // curr!=NULL && curr->right == NULL
       curr = curr->right;
}
      return curr;

    } 

Node * deletionBST(Node * root , int key){
    // if BST is empty
    if(root == NULL){
        return root;
    }

    if(root->value > key){
        root->left = deletionBST(root->left , key);
    }

    else if(root->value < key){
        root->right = deletionBST(root->right , key);
    }
    else{  // root->value = key (root is the node to be deleted)
         
         // if node have no child
         if(root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
         }
         
         // if node have only one child
         
         else if(root->left==NULL){  // only have right child
               Node * temp = root->right;
               free(root);
               return temp; // it means root->right = root->right->right
         }

         else if(root->right == NULL){
               Node * temp = root->left;
               free(root);
               return temp;
         }

         // if node have both the child
         else{
            // we'll find just smaller value then current root and it will be in the right most value of left subTree
            Node * justSmallerNode = largestNodeBST(root->left);
            // now we'll replace the root node with justSmallerValue node
            root->value = justSmallerNode->value;
            // now we'll call deletion process of just smaller value node for the left subTree
            root->left = deletionBST(root->left , justSmallerNode->value);
            // here it means that left sub tree is equal to tree after deleting the node 
         }
    }
      
      return root;
}

void inorderTraversal(Node * root){

    if(root == NULL){
        return;
    }

    inorderTraversal(root->left);
    cout<<root->value<<"  ";
    inorderTraversal(root->right);
}

int main(){

    BST bst;

    InsertionBST(bst.root , 3);
    InsertionBST(bst.root , 1);
    InsertionBST(bst.root , 4);
    InsertionBST(bst.root , 6);
    InsertionBST(bst.root , 2);

    inorderTraversal(bst.root);
    cout<<endl;

    BST bst2;
    bst2.root = insertBSTrecursive(bst2.root , 3);
    InsertionBST(bst2.root , 1);
    InsertionBST(bst2.root , 4);
    InsertionBST(bst2.root , 6);
    InsertionBST(bst2.root , 2);

    inorderTraversal(bst2.root);
    cout<<endl;  

    cout<<searchBSTrecursive(bst.root , 8)<<endl;  
    cout<<searchBSTrecursive(bst2.root , 6)<<endl;  
    
    bst.root = deletionBST(bst.root , 6);
    inorderTraversal(bst.root);
    cout<<endl;

    return 0;

}

//     3
//  1     4
//    2     6