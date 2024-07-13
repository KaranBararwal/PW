#include<iostream>
#include<vector>
#include<list>
using namespace std;

vector <list <int> > graph;
int v; // no. of vertices

void add_edge( int src , int dest , bool bi_dir = true){
    // adding destination value at src index in array 
    graph[src].push_back(dest);
    if(bi_dir){ // then destination also have direction to the source
           graph[dest].push_back(src);
    }

}

void display(){
    for(int i = 0 ; i < graph.size(); i++){
        cout<<i<<" --> ";
        for( auto el : graph[i]){
            cout<<el<<"  ,  ";
        }
        cout<<endl;
    }
}

int main(){
    cout<<"enter the value of vertices "<<endl;
    cin>>v;
    
    graph.resize(v, list<int> ());
    int e;
    cout<<"enter the number of edges "<<endl;
    cin>>e;

    while(e--){
        int s,d;
        cout<<"enter source and destination for vertics"<<endl;
        cin>>s>>d;
        // for making it directed graph pass false in bi_dir
        add_edge(s,d);
    }

    display();
}