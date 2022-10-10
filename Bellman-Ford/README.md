# Bellman Ford Algorithm for Shortest Paths

The world is changing, and world governments are now proponents of Electric Vehicles becoming the norm on the streets. As a result, some of the city highways now offer rebate on fuel costs and other cash incentives for electric vehicles. Luckily for you, its time to save some cash. This rebate system can be modelled as some of the edges in the graph possibly having negative weights.

## Bellman Ford

The Bellman–Ford algorithm finds shortest paths from a starting node to all nodes of the graph. The algorithm can process all kinds of graphs, provided that the graph does not contain a cycle with negative length. If the graph contains a negative cycle, the algorithm can detect this.  

The algorithm keeps track of distances from the starting node to all nodes of the graph.
Initially, the distance to the starting node is 0 and the distance to all other nodes in infinite.
The algorithm reduces the distances by finding edge that shorten the paths until it is not possible to reduce any distance.

You can read about the algorithm [here](https://www.geeksforgeeks.org/bellman-ford-algorithm-dp-23/).  

## Key Idea

The key idea behind Bellman-Ford is this : it goes through all the edges of the graph, a total of $n-1$ times, where `n` is the number of nodes in the graph. At each iteration of the main loop, it calculates shortest paths with atmost that number of edges. The most number of edges in the shortest path can be $n-1$ and thus, the loop runs $n-1$ times.

## The algorithm

The following (pseudocode) algorithm determines the shortest distance from a node $x$ to all other nodes of a graph. The edges are assumed to be a 3-tuple of integers - $(a, b, w)$, where the edge runs from node $a$ to $b$, and has a weight $w$.  

```python
for n in nodes:
    distance[n] = INFINITY;
distance[x] = 0

for i in [1...n-1]:
    for e in edges:
        a, b, w = e.unpack()
        distance[b] = min(distance[b], distance[a] + w)
```

### Time Complexity

We go over every edge (say there are $m$ of them) of the graph, a total of $n-1$ times, which makes it an $\mathcal{O}(mn)$ algorithm.  

You can try a problem on Bellman-Ford [here](./Tunnel/README.md).

## Improving upon the algorithm

In practice, the final distances can usually be found faster than in n − 1 rounds.
Thus, a possible way to make the algorithm more efficient is to stop the algorithm
if no distance can be reduced during a round.

## SPFA

An improvement upon design of Bellman-Ford is the SPFA (Shortest Path Faster Algorithm). Instead of going through all the edges in each round, it chooses the edges to be examined in a more intelligent way.  
The algorithm maintains a queue of nodes that might be used for reducing the distances. First, the algorithm adds the starting node $x$ to the queue.
Then, the algorithm always processes the first node in the queue, and when an edge $a \rightarrow b$ reduces a distance, node $b$ is added to the queue.

Your task is to implement the SPFA and optimise the Bellman-Ford Algorithm.
