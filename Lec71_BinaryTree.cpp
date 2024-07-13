#include<iostream>
using namespace std;

class Node{
   
   public:
   int value;
   Node * right;
   Node * left;

   Node(int data){
    value = data;
    right = NULL;
    left = NULL;
   }
};

int main(){

    Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    cout<<"Root Node is "<<root->value<<endl;
    cout<<"Left child is "<<root->left->value<<endl;
    cout<<"Right child is "<<root->right->value<<endl;
    return 0;

}