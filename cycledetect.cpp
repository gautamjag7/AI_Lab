#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool hasCycle(const vector<vector<int>>& graph, int startVertex, vector<bool>& visited) {
    queue<pair<int, int>> q; // Queue to store vertex and its parent
    q.push({startVertex, -1}); // Start with the startVertex and parent -1
    visited[startVertex] = true;

    while (!q.empty()) {
        int currentVertex = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (int neighbor : graph[currentVertex]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push({neighbor, currentVertex});
            } else if (neighbor != parent) {
                // If the neighbor is visited and not the parent, then cycle detected
                return true;
            }
        }
    }
    return false; // No cycle found
}
int main() {
    int vertices = 6;
    vector<vector<int>> graph(vertices);
    // Adding edges to the graph
    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(3);
    graph[2].push_back(4);
    graph[3].push_back(4);
    graph[3].push_back(5);

    vector<bool> visited(vertices, false);

    bool cycle = false;
    for (int i = 0; i < vertices; ++i) {
        if (!visited[i] && hasCycle(graph, i, visited)) {
            cycle = true;
            break;
        }
    }

    if (cycle) {
        cout << "Cycle detected in the graph." << endl;
    } else {
        cout << "No cycle detected in the graph." << endl;
    }

    return 0;
}
