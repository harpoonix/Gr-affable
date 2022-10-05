# Dijkstra's algorithm for Shortest Paths

Through GPS satellites, the system of your car has been fed the map of a bustling metropolitan. As a part of the DSA team in the self-driving subsystem, you have to analyse the graph given to you and find the shortest path from one city to the other, or one locale in the city to the other.

## Dijkstra's Algorithm

Dijkstra’s algorithm finds shortest paths from the starting node to all nodes of the graph. The algorithm **requires** that there be **no negative weight edges** in the graph.  
Dijkstra’s algorithm is efficient, because it only processes each edge in the graph once, using the fact that there are no negative edges. You can read on up the algorithm [here](https://www.freecodecamp.org/news/dijkstras-shortest-path-algorithm-visual-introduction/#:~:text=Dijkstra's%20Algorithm%20finds%20the%20shortest,node%20and%20all%20other%20nodes.)  

## The algorithm

Dijkstra’s algorithm calculates the minimum
distances from a node $x$ to other nodes of the graph. The graph is stored as
adjacency lists so that `adj[a]` contains a pair $( b, w )$ always when there is an edge
from node $a$ to node $b$ with weight $w$.

## Improving the algorithm

We can substantially improve the algorithm to the point where its time complexity decreases significantly. Instead of going through all the nodes to check which unprocessed node has the minimum distance at every run of the loop, we can use a useful data structure - a priority queue.
The next node to be processed can be retrieved in logarithmic time, using a priority queue. The time complexity of the improved dijkstra is thus $\mathcal{O}(E \log(V))$ where $E$ is the number of edges and $V$ is the number of vertices/nodes in the graph.

### Queue

The min-priority queue $Q$ contains pairs of the form $( d, x )$,
meaning that the current distance to node $x$ is $d$, where priorities are decided by $d$. Any node whose distance has been reduced by an edge from the current selected node, is added to the priority queue.

You have to implement the optimised dijkstra's algorithm, which chooses the next node to be processed in logarithmic time. Can a node be added to the priority queue more than once? If so, how do you plan to resolve it?

> An important part of FOSS contributions is documentation. Explain why the algorithm fails for negative weight edges through comments in your code.
