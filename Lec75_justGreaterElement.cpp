#include<iostream>
#include<vector>
using namespace std;

class Node {
   public:

   int data;
   vector <Node*> children;  

   Node(int data){
    this->data = data;
   }
};

Node * justGreaterElement(Node * root , int key , Node * &ans){

    if(root == NULL){
        return NULL;
    }

    if(root->data > key && ( ans == NULL || root->data < ans->data))  { // ans = NULL for root node
          ans = root; // updating ans
    }
     
     // recursively call for all the children of Tree
     for(Node * child : root->children ){
     justGreaterElement( child , key , ans );
     }
}
int main(){
    int n;

    Node * root = new Node(1);
    root->children.push_back(new Node (2));
    root->children.push_back(new Node(3));
    root->children.push_back(new Node (4));
    root->children[0]->children.push_back(new Node(5));
    root->children[0]->children.push_back(new Node(6));
    root->children[2]->children.push_back(new Node(7));
    
    cout<<"enter the value "<<endl;
     cin>>n;

     Node * ans = NULL;
     
     justGreaterElement(root , n , ans);
     if(ans == NULL){
        cout<<"no grater value "<<endl;
     }else{
     cout<<"just grater value is in tree "<<ans->data<<endl;
     }

    return 0;
}

//          1
//     2   3     4
//    5 6        7