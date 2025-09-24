// directed and weighted
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int vertices, edges;
    cout << "Enter the number of vertices and edges: ";
    cin >> vertices >> edges;

    vector<vector<pair<int,int>>> adjList(vertices);

    cout << "Enter the edges (u v w): " << endl;
    for (int i = 0; i < edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adjList[u].push_back({v, w});
    }

    cout << "\nAdjacency List:" << endl;
    for (int i = 0; i < vertices; i++) {
        cout << i << " -> ";
        for (auto neighbor : adjList[i]) {
            cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
        }
        cout << endl;
    }

    return 0;
}

// diagram

//        A
//     3 /  \4
//      /    \
//     v   9  v
//     B------>C
//   6 |       | 2
//     |       |
//     v       v
//     D------>E
//        10


// A - 0
// B - 1
// C - 2   
// D - 3
// E - 4

// Output

// Enter the number of vertices and edges: 5 6
// Enter the edges (u v w): 
// 0 1 3
// 0 2 4
// 1 2 9
// 1 3 6
// 2 4 2
// 3 4 10

// Adjacency List:
// 0 -> (1, 3) (2, 4) 
// 1 -> (2, 9) (3, 6) 
// 2 -> (4, 2) 
// 3 -> (4, 10) 
// 4 -> 


