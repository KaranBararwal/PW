#include <bits/stdc++.h>
using namespace std;
 
 
void bfs(vector<vector<int>> &g, int N)
{
    vector<bool> visited(N);
    int startingNode = 0;
 
 
    queue<int> q;
    q.push(startingNode);
    visited[startingNode] = true;
 
 
    cout << "BFS traversal: ";
    while (q.size())
    {
        int currNode = q.front();
        q.pop();
        cout << currNode << "->";
 
 
        for (auto &neigh : g[currNode])
        {
            if (!visited[neigh])
            {
                visited[neigh] = true;
                q.push(neigh);
            }
        }
    }
    cout << "end\n";
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
 
 
    bfs(g, N);
 
 
    return 0;
}