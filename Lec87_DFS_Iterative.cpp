#include <bits/stdc++.h>
using namespace std;
 
 
void dfs(vector<vector<int>> &g, int N)
{
    vector<bool> visited(N);
    int startingNode = 0;
 
 
    stack<int> s;
    s.push(0);
    visited[0] = true;
 
 
    cout << "DFS traversal: ";
    while (s.size())
    {
        int currNode = s.top();
        s.pop();
        cout << currNode << "->";
 
 
        for (auto &neigh : g[currNode])
        {
            if (!visited[neigh])
            {
                visited[neigh] = true;
                s.push(neigh);
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
 
 
    dfs(g, N);
 
 
    return 0;
}