#include<iostream>
#include<vector>
#include<list>
using namespace std;

vector <list <pair <int , int > > > graph;
int v; // no. of vertices

void add_edge( int src , int dest , int wt , bool bi_dir = true){
    // adding destination value at src index in array 
    graph[src].push_back(make_pair(dest ,wt));
    if(bi_dir){ // then destination also have direction to the source
           graph[dest].push_back(make_pair(src ,wt));
    }
}

void display(){
    for(int i = 0 ; i < graph.size(); i++){
        cout<<i<<" --> ";
        for( auto el : graph[i]){
            cout<<"(" <<el.first<<"  "<<el.second<<")  ,  ";
        }
        cout<<endl;
    }
}

int main(){
    cout<<"enter the value of vertices "<<endl;
    cin>>v;
    
    graph.resize(v, list < pair <int ,int> > ());
    int e;
    cout<<"enter the number of edges "<<endl;
    cin>>e;

    while(e--){
        int s,d,wt;
        cout<<"enter source , destination and weight for vertics"<<endl;
        cin>>s>>d>>wt;
        // for making it directed graph pass false in bi_dir
        add_edge(s,d,wt);
    }
    display();
    return 0;
}