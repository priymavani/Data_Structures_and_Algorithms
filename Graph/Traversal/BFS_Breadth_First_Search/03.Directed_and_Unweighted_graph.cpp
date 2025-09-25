
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(int sp ,vector<vector<int>> adj , int vertice ){
    vector<bool> visited(vertice , 0) ;
    queue<int> q;
    
    visited[sp] = 1;
    q.push(sp);
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << " " ;
        
        for(int i = 0; i<adj[node].size() ; i++){
            int n = adj[node][i] ;
            if(!visited[n]){
                q.push(n);
                visited[n] = 1;
            }
        }
        
    }
}
int main() {

   int vertice = 5;
    vector<vector<int>> adj(vertice);

    // Directed edges (one way)
    adj[0] = {1, 2};
    adj[1] = {3};
    adj[2] = {3};
    adj[3] = {4};
    adj[4] = {};  // no outgoing edge

    cout << "Directed Unweighted BFS: ";
    BFS(0, adj, vertice);

    return 0;
}
