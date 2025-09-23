

#include <vector>
#include <iostream>
using namespace std;

int main(){
    int vertice,edge ;
    vertice = 5;
    edge = 6;
    
    vector<vector<int>> adj(vertice , vector<int>(vertice , 0));
    
    int u,v,value;
    u=2;
    v=1;
    value = 3;
    
    // directed and weighted 
    for(int i = 0 ; i<edge ; i++){
        adj[u][v] = value;
    }
    
    for(int i =0; i<vertice ; i++){
        for(int a = 0 ; a<vertice ; a++){
            cout<< adj[i][a] << " ";
        }
        cout << endl;
    }
    
    return 0;
}