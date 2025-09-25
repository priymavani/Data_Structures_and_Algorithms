
// Undirected and weighted BFS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(int sp, vector<vector<pair<int,int>>> adj, int vertice) {
    vector<bool> visited(vertice, 0);
    queue<int> q;

    visited[sp] = 1;
    q.push(sp);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int i = 0; i < adj[node].size(); i++) {
            int n = adj[node][i].first;   // neighbor
          
            if (!visited[n]) {
                q.push(n);
                visited[n] = 1;
            }
        }
    }
}

int main() {
    int vertice = 5;
    vector<vector<pair<int,int>>> adj(vertice);

    // Undirected weighted edges
    adj[0].push_back({1, 10});
    adj[1].push_back({0, 10});  // because undirected

    adj[0].push_back({2, 5});
    adj[2].push_back({0, 5});

    adj[1].push_back({3, 2});
    adj[3].push_back({1, 2});

    adj[2].push_back({3, 3});
    adj[3].push_back({2, 3});

    adj[3].push_back({4, 1});
    adj[4].push_back({3, 1});

    cout << "Undirected Weighted BFS: ";
    BFS(0, adj, vertice);
}
