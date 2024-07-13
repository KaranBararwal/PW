#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Node {
   public:

   char data;
   vector <Node*> children; // storing addresses of all the children

   Node(char data){
    this->data = data;
   }
};

void LevelOrderTraversal( Node * root){

    if(root == NULL){
        return;
    }

    queue <Node* > q;
    q.push(root);

    while(!q.empty()){
          
          int currentLevelNodes = q.size();
          while(currentLevelNodes--){

            // dequeue
            Node * curr = q.front();
            q.pop();
            cout<<curr->data<<"  ";  

            // enqueue all the child nodes
            // for each loop

            for(Node * child : curr->children){   // here don't use root->children i dont't know why but it makes infinite loop
                q.push(child);
            }          
          }
          cout<<endl;
    }
    return;
}

int main(){

    Node * root = new Node('A');
    root->children.push_back(new Node ('B'));
    root->children.push_back(new Node('C'));
    root->children.push_back(new Node ('D'));
    root->children[0]->children.push_back(new Node('E'));
    root->children[0]->children.push_back(new Node('F'));
    root->children[2]->children.push_back(new Node('G'));
    LevelOrderTraversal(root);

    return 0;
}

//          A
//     B   C      D
//    E F        G