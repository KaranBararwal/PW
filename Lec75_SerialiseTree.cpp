#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
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

Node * deserialiseTreeHelper(int nodeValue , unordered_map <int , string> mp){
     
     Node * node = new Node(nodeValue);
     string nodeStr = mp[nodeValue]; // " 4 : 2 , 34 , 56 , 100 "
      
     if(nodeStr[0] == '0'){
        // leaf node
        return node;
     } 

     int breakPos = nodeStr.find(':');
     int childNodesNumber = stoi(nodeStr.substr(0 , breakPos));
     string childNodesString = nodeStr.substr(breakPos+1); // "2 , 34 , 56 , 100"
     
     int start = 0;
     for(int i=0 ; i<childNodesNumber; i++){

       // int end = childNodesString.find(','); // here we need to specify from where to we are finding the , otherwise it'll always return the first comma
       // so it can be written as
       int end = childNodesString.find(',' , start);

        if(end == string :: npos){ // if it is at last child
            end = childNodesString.size();
        }

        int childNodeValue = stoi(childNodesString.substr(start , end));
        node->children.push_back(deserialiseTreeHelper(childNodeValue,mp));

        start = end+1;
     }
     return node;
}

void serialiseTree( Node * root , string &ans){
      
      if(root == NULL){
        return;
      }
      
      // using to_string for converting data_type to string
      ans+= to_string(root->data) + ':' + to_string(root->children.size()) + ':';
      // now adding all the children

      for(Node * child : root->children){
        ans += to_string(child->data) + ',';
      }

      // if there child of node then after last child there will a comma so we have to remove it
      if(root->children.size()){
            ans.pop_back();
      }

       ans+="\n"; // don't write cout<<endl it won't work here

      // now we'll call this serilise function for every node in the tree

      for(Node * child : root->children){
        serialiseTree(child , ans);
      }
}

Node * deserialiseTree(string serialiseString){

    if(serialiseString == ""){
        return NULL;
    }
    
    // creating a map that is storing the node value and its child nodes string
    unordered_map<int , string> mp;

    int start =0;

    for(int i= 0 ; i<serialiseString.size() ; i++){
        if(serialiseString[i] == '\n'){
            // it mean it has travel through one node searial order (10 : 4 : 2 , 34 , 56 , 100)
            // now we'll store it in another string
            string nodeStr = serialiseString.substr(start , i-start);
            // 10 : 4 : 2 , 34 , 56 , 100

            // now we'll find the node value
            int breakPos1 = nodeStr.find(':');
            int nodeValue = stoi(nodeStr.substr(0,breakPos1)); // we have to convert it in integer by usign stoi
            
            // storing all the child node value in map containing key value as root
            mp[nodeValue] = nodeStr.substr(breakPos1+1); // "4 : 2 , 34 , 56 , 100"  //   string after breakPos1+1 to end
            
            // updating start for next node
            start = i+1;
        }
    }

    // we have to call the deserilsed function recusively for every child of root node

    int rootNodeValue = stoi(serialiseString.substr(0,serialiseString.find(':')));
    return deserialiseTreeHelper(rootNodeValue , mp);
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
    
    string ans = "";
    serialiseTree(root , ans);
    cout<<ans;

    Node * deserialiseRoot = deserialiseTree(ans);
    cout<<"tree's level order traversal is "<<endl;
    LevelOrderTraversal(deserialiseRoot);

 
    return 0;
}