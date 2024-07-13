#include <iostream>
#include<vector>
#include <queue>
#include<stack>
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

vector <int> ReverseLevelOrder(Node * rootNode){

    vector <int> ans;
    // if tree is empty
    if(rootNode == NULL){
        return ans;
    }

    queue <Node*> q;
    stack <Node*> s;
    q.push(rootNode);

    while(!q.empty()){

        int nodesAtCurrentLevel = q.size();

        while(nodesAtCurrentLevel--){

            Node * currNode = q.front();
            q.pop();

            s.push(currNode);
            
            if(currNode->right){    // first we'll insert right child cuz for reverse order we need to print left child first
               q.push(currNode->right);
            }

            if(currNode->left){
                q.push(currNode->left);
            }

        }
    }

    while(!s.empty()){
        ans.push_back(s.top()->value); // cuz stack have nodes not the values
        // cout<<s.top()->value;
        s.pop(); 
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

      cout<<"reverse level order is ";
      vector <int> ans = ReverseLevelOrder(root);
      for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<"  ";
      }
      return 0;            

}