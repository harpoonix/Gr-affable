#include<iostream>
#include<vector>
using namespace std;


// Analyse the problem as a Directed Graph(G) with n nodes and m edges
// Print "YES" if you can travel between all pairs of Vertices of G
// "NO" if the can't travel otherwise and also print 
// the pair of vertices that we cannot travel in case of "NO"

using vi = vector<int>;
#define pb push_back
#define mp make_pair
#define f first
#define s second

vi adj[100000][2];          // Adjacency list
bool vis[100000];

void dfs(int v, int x) {
	vis[v] = true;
	
    // Implement this dfs function
    // v is the index of the node in adj list
    // x is the second index denoting the start/end

}

int main(){
    int n,m;        
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int start, end;
        cin >> start >> end;
        adj[start][0].pb(end);
        adj[end][1].pb(start);
        /**
         * A slight error is occuring while allocating values to start & end
         * Fix this small issue to go forward into the problem
         */
    }

    // Do DFS starting from any one Vertex
    dfs(0, 0);

	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			cout << "NO" << '\n';

            // You also had to print a pair such that you cannot travel it
            // Do implement that here 
            
		}
	}
	cout << "YES" << '\n';
}