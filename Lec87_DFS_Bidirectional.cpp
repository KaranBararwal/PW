#include <iostream>
#include <vector>
using namespace std;
 
void dfs(int node, vector<bool>& visited, const vector<vector<int>>& graph) {
    visited[node] = true;
    cout << node << " "; // Process the current node (e.g., print or perform some operation)
 
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited, graph);
        }
    }
}
 
int main() {
    int n = 7; // Number of nodes in the graph
    vector<vector<int>> graph = {
        {1, 2},
        {3, 4},
        {5},
        {},
        {6},
        {},
        {}
    };
 
    int starting_node = 0;
 
    vector<bool> visited(n, false);
    dfs(starting_node, visited, graph);
 
    return 0;
}