#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adjMatrix;
    vector<vector<int>> adjList;

public:
    Graph(int vertices) : V(vertices) {
        adjMatrix = vector<vector<int>>(V, vector<int>(V, 0));
        adjList = vector<vector<int>>(V);
    }

    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<int> bfs(int start) {
        vector<bool> visited(V, false);
        vector<int> result;
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            result.push_back(node);

            for (int neighbor : adjList[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        return result;
    }

    vector<int> dfs(int start) {
        vector<bool> visited(V, false);
        vector<int> result;

        dfsUtil(start, visited, result);

        return result;
    }

private:
    void dfsUtil(int node, vector<bool>& visited, vector<int>& result) {
        visited[node] = true;
        result.push_back(node);

        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                dfsUtil(neighbor, visited, result);
            }
        }
    }
};

int main() {
    int n, m;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    Graph graph(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cout << "Enter an edge (u v): ";
        cin >> u >> v;
        graph.addEdge(u, v);
    }

    while (true) {
        char choice;
        cout << "Enter your choice (B/b for BFS, D/d for DFS, T/t for Both, X/x for Exit): ";
        cin >> choice;
        if (choice == 'B' || choice == 'b') {
            int start_node;
            cout << "Enter the starting node for BFS: ";
            cin >> start_node;
            vector<int> bfs_result = graph.bfs(start_node);
            cout << "BFS Traversal:";
            for (int node : bfs_result) {
                cout << " " << node;
            }
            cout << endl;
        } else if (choice == 'D' || choice == 'd') {
            int start_node;
            cout << "Enter the starting node for DFS: ";
            cin >> start_node;
            vector<int> dfs_result = graph.dfs(start_node);
            cout << "DFS Traversal:";
            for (int node : dfs_result) {
                cout << " " << node;
            }
            cout << endl;
        } else if (choice == 'T' || choice == 't') {
            int start_node;
            cout << "Enter the starting node for Both BFS and DFS: ";
            cin >> start_node;
            vector<int> bfs_result = graph.bfs(start_node);
            vector<int> dfs_result = graph.dfs(start_node);
            cout << "BFS Traversal:";
            for (int node : bfs_result) {
                cout << " " << node;
            }
            cout << endl;
            cout << "DFS Traversal:";
            for (int node : dfs_result) {
                cout << " " << node;
            }
            cout << endl;
        } else if (choice == 'X' || choice == 'x') {
            break;
        }
    }

    return 0;
}
