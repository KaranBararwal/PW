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

void LevelOrderTraversal(Node *rootNode)
{

    // case of empty tree
    if (rootNode == NULL)
    {
        return;
    }
    queue <Node *> q;
    q.push(rootNode);

    while (!q.empty())
    {

        int nodesAtCurrentLevel = q.size();
        while (nodesAtCurrentLevel--)
        {

            Node *currNode = q.front();
            q.pop();
            cout << currNode->value << "  ";

            if (currNode->left)
            { // currNode->left!=NULL
                q.push(currNode->left);
            }

            if (currNode->right)
            {
                q.push(currNode->right);
            }
        }
        cout << endl;
    }
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

      LevelOrderTraversal(root);
      return 0;            

}