#include <bits/stdc++.h>
using namespace std;
 
 
void dfs(int currNode, vector<bool> &visited, vector<vector<int>> &g)
{
    // mark the current node as visited
    visited[currNode] = true;
 
 
    cout << currNode << "->";
 
 
    // check the neighbors
    for (auto &neigh : g[currNode])
    {
        if (!visited[neigh])
        {
            dfs(neigh, visited, g);
        }
    }
}
 
 
int main()
{
    int N; // number of nodes
    cin >> N;
    vector<vector<int>> g(N);
    int M; // number of edges
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int u, v; // edge from u to v;
        cin >> u >> v;
        g[u].push_back(v);
    }
 
 
    int startingNode = 0;
    vector<bool> visited(N);
    cout << "DFS traversal: ";
    dfs(0, visited, g);
    cout << "end\n";
 
 
    return 0;
}