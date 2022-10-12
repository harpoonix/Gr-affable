#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;

void make_adjacency_list(vector<vector<pii>> &adj, int m) {
    cout<<"Making Adjacency List\n";
    int u, v, w;
    for (int i=0; i<m; i++) {
        cin>>u>>v>>w;
        u--; v--;
        adj[u].push_back(pii(v, w));
        adj[v].push_back(pii(u, w));
    }
}

void dijkstra(int start, vector<vector<pii>> &adj, vb &visited, vi &lengths){
    int n = visited.size();
    visited[start] = 1;
    lengths[start] = 0;
    for (int i=0; i<n; i++) {
        // Run n loops through the nodes, taking one unprocessed node at a time
        int least = -1;
        for (int j=0; j<n; j++) {
            if (!visited[j] && (least==-1 || lengths[j] < lengths[least])){
                least = j;
            }
        }
        if (lengths[least]==INT32_MAX/2){
            break;
        }

        // Found the unvisited node with least distance
        visited[least] = true;
        for (auto edge : adj[least]){
            int to = edge.first;
            int weight = edge.second;
            lengths[to] = min(lengths[least] + weight, lengths[to]);
        }
    }
}

void print_distances(int n, vi &lengths){
    for (int i=0; i<n; i++) {
        cout<<"Distance of "<<i+1<<" is "<<lengths[i]<<"\n";
    }
}

int main(){
    int n, m; cin>>n>>m;
    int source; cin>>source;
    source--;
    vector<vector<pii>> adj;
    adj.resize(n, vector<pii>(0));

    // Take input as (start node, end node, weight) tuple and make an adjacency list
    make_adjacency_list(adj, m); 

    vector<bool> visited;
    visited.resize(n, 0); // All the nodes are unvisited in the beginning
    vector<int> lengths;
    lengths.resize(n, INT32_MAX/2);

    dijkstra(source, adj, visited, lengths);

    print_distances(n, lengths);

}
