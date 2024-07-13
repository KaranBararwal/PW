#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class Node {
   public:

   int data;
   vector <Node*> children;  

   Node(int data){
    this->data = data;
   }
};

void MirrorTree(Node * root){
    // Time = O(n)
    // Space = O(h)+ O(m) , m = max number of nodes at particular level
    if(root == NULL){
        return;
    }

    if(root->children.size()<2){  // no need of reverse in one child
        return;
    }

    reverse(root->children.begin() , root->children.end());
    // we will recursively call reverse function for all the children of every node

    for(Node * child : root->children){
        MirrorTree(child);
    }
}

void LevelOrderTraversal(Node * root){
    
    if(root == NULL){
        return;
    }
    
    queue <Node*> q;
    q.push(root);

    while(!q.empty()){

        int currentLevelNodes = q.size();
        while(currentLevelNodes--){

            Node * curr = q.front();
            q.pop();
            cout<<curr->data<<"  ";

            // enqueue all the child nodes for each node
            for(Node * child : curr->children){
                q.push(child);
            }
        }
        cout<<endl;
    }
    return;
}

int main(){
    Node * root = new Node(10);
    root->children.push_back(new Node(2));
    root->children.push_back(new Node(34));
    root->children.push_back(new Node(56));
    root->children.push_back(new Node(100));
    root->children[1]->children.push_back(new Node(1));
    root->children[3]->children.push_back(new Node(7));
    root->children[3]->children.push_back(new Node(8));
    root->children[3]->children.push_back(new Node(9));
    LevelOrderTraversal(root);

    MirrorTree(root);
    cout<<endl<<"the mirror tree is "<<endl;
    LevelOrderTraversal(root);
 
    return 0;
}