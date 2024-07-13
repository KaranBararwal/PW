#include <iostream>
#include<vector>
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

vector <int> rightView(Node * rootNode){
    
    vector<int> ans;
    // if tree is empty
    if(rootNode==NULL){
        return ans;
    }

    queue<Node*> q;
    q.push(rootNode);

    while(!q.empty()){

        int NodesAtCurrentLevel = q.size();

        while(NodesAtCurrentLevel){  // we can't do here (NodesAtCurrentNode--) cuz we first need do to do some operations with that node

            Node * currNode = q.front();
            q.pop();

            if(NodesAtCurrentLevel==1){  // it is the right most node
               ans.push_back(currNode->value);
            //    cout<<currNode->value;
            }

            // if it has left child

            if(currNode->left){
                q.push(currNode->left);
            }

            // if it has right child

            if(currNode->right){
                q.push(currNode->right);
            }

            NodesAtCurrentLevel--;
        }
    }
    return ans;
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

      cout<<"rigth side view is ";
      vector <int> ans = rightView(root);
      for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<"  ";
      }
      return 0;            

}