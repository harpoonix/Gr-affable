#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main(){
   int n; //no of vertices
   cin>>n;
   int m; //no of edges
   cin>>m;
   vector<vector<pii>> adj(n); //adjacency list to store graph
   for(int i=0;i<m;i++){
        vector<int> p(3);
        //vector to hold (end vertex, weight) for a given edge at index (start vertex)
        for(int j=0;j<3;j++){
            cin>>p[j];
        }
        // n1 -- n2 connection
        adj[p[0]].push_back(pii(p[1], p[2]));
        // n2 -- n1 connection
        adj[p[1]].push_back(pii(p[0], p[2]));
   }
   //store start node
   int x;
   cin>>x;

   //efficient djikstra's algorithm using priority queue
   priority_queue<pii, vector<pii>, greater<pii>> buffer;
   vector<int> distances(n, INT32_MAX); //store largest possible + ve 32 bit integer as initial distance 

   //store start node in buffer with dist 0
   //format for buffer is (distance of node from start, node)
   buffer.push(pii(0, x));
   distances[x] = 0;

   while(!buffer.empty()){
      //keep iterating until priority queue is not empty
      pii temp = buffer.top();
      //pick the closest node 
      buffer.pop();
      for(auto l: adj[temp.second]){
         //check all adjacent neighbours of the closest node
         int v = l.first;
         int w = l.second;
         //check if the distance of the particular node through the closest node, is lesser than the older stored distance
         if(distances[v] > distances[temp.second] + w){
            //note this only works if w >= 0 as dijkstra's algorithm is greedy 
            //and we visit all nodes only once in a greedy approach, and we initialize all distances initially as infinity
            //so if we have a negative weight, we might incorrectly select a path with few negative weights, than the most optimum path 
            distances[v] = distances[temp.second] + w;
            //update the buffer with this node and its distance
            buffer.push(pii(distances[v], v));
         }
      }
   }

   //format <node> <distance from start> 
   for(int i=0; i<n; i++){
      cout<<i<<" "<<distances[i]<<endl;
   }

}