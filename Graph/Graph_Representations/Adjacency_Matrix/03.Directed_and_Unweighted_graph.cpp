

#include <vector>
#include <iostream>
using namespace std;

int main(){
    int vertice,edge ;
    vertice = 5;
    edge = 6;
    
    vector<vector<bool>> adj(vertice , vector<bool>(vertice , 0));
    
    int u,v;
    u=2;
    v=1;
    
    
    // directed and unweighted 
    for(int i = 0 ; i<edge ; i++){
        adj[u][v] = 1;
    }
    
    for(int i =0; i<vertice ; i++){
        for(int a = 0 ; a<vertice ; a++){
            cout<< adj[i][a] << " ";
        }
        cout << endl;
    }
    
    return 0;
}