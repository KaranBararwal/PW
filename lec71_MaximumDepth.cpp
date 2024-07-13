#include <iostream>
#include <queue>
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

int MaximumDepth(Node * rootNode){
    // base case
    if(rootNode==NULL){
        return 0;
    }

   // recursive case
   int leftDepth = MaximumDepth(rootNode->left);
   int rightDepth = MaximumDepth(rootNode->right);

   return (max(leftDepth,rightDepth) + 1);
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

      cout<<"maximum depth is "<<MaximumDepth(root);
      return 0;            

}