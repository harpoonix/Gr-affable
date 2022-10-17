#include <iostream>
#include<vector>
using namespace std;

#define F first
#define S second
#define pb push_back
#define pp pair<int,int>

typedef vector<int> vi;

vector <pp> scGraph;        // The SinglyConnectedGraph
vector <pp> graph[100000];  // The initial Graph given
bool visited[100000];


void dfs(int node = 1){
    visited[node] = true;
    for(auto i: graph[node]){
        if(!visited[i.first]){
            dfs(i.first);
        }
    }

    /**
     * Edit this normal dfs function to 
     * check existence of bridge in the graph and its singly connectedness
     * To construct the scGraph for printing, set a direction to each node
     * Assigning the direction in which the node was traversed before will work!
     */

}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        pp temp;        // create a temporary pair
        temp.first = y;
        temp.second = i;
        graph[x].pb(temp);        // An error has been thrown (pb expected only one parameter)
        temp.first = x;
        graph[y].pb(temp);        // Can you figure it out ? (Yes!)
    }
    dfs();
    /**
     * Print the required output after performing modifies dfs traversal
     * 
     */
}
