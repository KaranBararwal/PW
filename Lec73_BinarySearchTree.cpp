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