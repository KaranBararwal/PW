#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *left;
    Node *right;

    Node(int data)
    {
        value = data;
        left = right = NULL;
    }
};

class BST
{ // it will create a empty BST
public:
    Node *root;

    BST()
    {
        root = NULL;
    }
};

void InsertionBST(Node *&root, int val)
{ // here pass by reference otherwise it will don't get updated

    Node *newNode = new Node(val);
    // if the BST is empty
    if (root == NULL)
    {
        root = newNode;
        return;
    }

    Node *current = root;

    while (true)
    {

        if (current->value > val)
        { // it means root node value is greater then given value
            // so we'll insert the value at left subtree of root

            // if left child of current root node doesn't exist so we'll insert value there
            if (current->left == NULL)
            {
                current->left = newNode;
                return;
            }
            // if left child of the current root exist then we need to check for that node
            // so we'll make that node current node
            current = current->left;
        }

        else
        { // current->value < val
            // it means root node value is less then given value
            // so we'll insert the value at right subtree of root node

            // if right child of current root doesn't exist so we'll insert value there
            if (current->right == NULL)
            {
                current->right = newNode;
                return;
            }

            // if right child of the current root exist then we need to check for that node
            // so we'll make that node current node
            current = current->right;
        }
    }
}

void  inorderPreSuccBST(Node *root, Node * &pre, Node * &succ, int key)
// pass by reference cuz we need output of these value in the main function
// Time = O(h)
// Space = O(h)
{

    // if BST is empty
    if (root == NULL)
    {
        return ;
    }

    // if the root is equal to the key
    if (root->value == key)
    {

        // for predecessor we need to find the right most node of left SubTree
        if (root->left != NULL)
        {
            Node *temp = root->left;

            while (temp->right != NULL)
            {
                temp = temp->right;
            }

            pre = temp;
        }

        // for successor we need to find the left most node of right SubTree

        if (root->right != NULL)
        {

            Node *temp = root->right;

            while (temp->left != NULL)
            {
                temp = temp->left;
            }

            succ = temp;
        }
    }

    else if(root->value > key){  // root can be successor
          succ = root;
          inorderPreSuccBST(root->left , pre , succ , key);
    }

    else{ // root->value < key
        // root can be predecessor
         pre = root;
         inorderPreSuccBST(root->right , pre , succ , key);

    }
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
    
     Node * pre = NULL;
     Node * succ = NULL;

     inorderPreSuccBST(bst.root , pre , succ ,3);
    
     if(pre!=NULL){
        cout<<"pre = " <<pre->value<<endl;
     }
     else{
        cout<<"pre = NULL"<<endl;
     }

     if(succ!=NULL){
        cout<<"succ = " <<succ->value<<endl;
     }
     else{
        cout<<"succ = NULL"<<endl;
     }     
      return 0;
}

//     3
//  1     4
//    2     6