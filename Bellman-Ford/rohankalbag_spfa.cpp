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

   vector<int> distances(n, INT32_MAX); //store largest possible + ve 32 bit integer as initial distance 

   //buffer stores nodes
   queue<int> buffer;
   //create a bool array to check if the node is in the queue
   vector<bool> inbuff(n+1, false);

   //store start node in buffer with dist 0
   buffer.push(x);
   distances[x] = 0;
   inbuff[x] = true;

   //improved bellman ford (sfpa algorithm)
   while(!buffer.empty()){
        //keep going till queue is not empty
        int currnode = buffer.front();
        buffer.pop();
        inbuff[currnode] = false;

        //check all the edges connected to this node
        for(auto edge: adj[currnode]){
            int v = edge.first;
            int w = edge.second;
            if(distances[v] > distances[currnode] + w){
                //if the edge a --> b reduces a distance, then add the node b to the queue
                distances[v] = distances[currnode] + w;
                //check if the node b is already in the queue
                if(!inbuff[v]){
                    //if not add it into the queue and remember that its in there
                    inbuff[v] = true;
                    buffer.push(v);
                }
            }
        }

   }

   //format <node> <distance from start> 
   for(int i=0; i<n; i++){
      cout<<i<<" "<<distances[i]<<endl;
   }

}