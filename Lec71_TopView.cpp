#include <iostream>
#include<vector>
#include <queue>
#include<map>
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

vector <int> topViewBinaryTree(Node * rootNode){

    vector<int> ans;
    if(rootNode == NULL){  // empty Binary Tree
        return ans;
    }

    queue < pair < Node* , int> > q;
    q.push(make_pair(rootNode,0));
    map<int , int > m;

    while(!q.empty()){

        int nodesAtCurrentLevel = q.size();

        while(nodesAtCurrentLevel--){

            pair <Node* , int> currPair = q.front(); // it is returning a pair
            Node * currNode = currPair.first;
            int currColumn = currPair.second;
            q.pop(); // we have removed our first pair here

            if(m.find(currColumn) == m.end()) {  // it means for this column there is no value is inserted
            // it is the first node of the column so we'll insert in map
               m[currColumn] = currNode->value; 
               // here if we'll mistakely write == then code will run and it will gove answer as 0 0 0 0 0 ....
            }

            // if it has left child
            if(currNode->left){
                q.push(make_pair(currNode->left , currColumn-1));
            }

            // if it has right child
            if(currNode->right){
                q.push(make_pair(currNode->right , currColumn+1));
            }
        }
    }

    for(auto itr : m){
        ans.push_back(itr.second); // it will be in ordered way
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

      cout<<"top view is ";
      vector <int> ans = topViewBinaryTree(root);
      for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<"  ";
      }
      return 0;            

}