#include<iostream>
#include<vector>
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

Node * SortedArrayToBST(vector<int> v , int start , int end){
    // Time = O(n)
    // Space = O(h) = O(logn)
     // base case
     if(start>end){
        return NULL;
     }

     int mid = (start+end)/2;
     // making middle element the root node
     Node * root = new Node(v[mid]);
    
     // recursive case
     root->left = SortedArrayToBST(v , start , mid-1); // recursively creating left subtree from leftHalf of array
     root->right = SortedArrayToBST(v , mid+1 ,end);   // recursively creating right subtree from rightHalf of array
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
    int n;
    cout<<"enter the size of vector "<<endl;
    cin>>n;

    vector <int> v(n);

    cout<<"enter "<<n<<" elements "<<endl;

    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    BST bst;
    bst.root = SortedArrayToBST(v,0,n-1);

    inorderTraversal(bst.root);
    cout<<endl;
    
}