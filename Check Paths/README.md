# Check Paths

Let's start our journey and drive through the land of Data Structures. But, to start, we first need to know whether it is possible for us to reach somewhere. Suppose you are at your starting city Mumbai and you want to plan a Road trip to a pleasant and peaceful destination. First, we will check that Is it possible to reach a certain destination from our starting point or not? Let's solve this problem.

## Problem Statement

Say there are $n$ number of destinations that we have filtered out for our Trip. We got the Map of the area and found the data of Roads that connect different tourist/scenic spots or places of interests to each other. Call the number of available routes as $m$. Your task is to check if you can travel from any city/place to any other using the routes that are available to you.

### Input

- First line : Two integers $n$ and $m$, where $n$ denotes the number of places of interest to visit and $m$ denotes the Number of available routes. For simplicity, we are numbering the places of interests as integers $1,2,.....n$.
- Next $m$ lines : Each line has two integers $x$ and $y$, representing that there exists a route connecting place $x$ to $y$. All the routes available are **one-way** only.

### Output

Print :

- ``YES`` : If all Tourist spots are possible to travel from any other Touristspot
- ``NO``  : Otherwise.
Also, print the spots $p, q$ such that you are not able to travel between them

## Idea

Notice that if one vertex can **be reached** by all other vertices and every other vertex can be reached from this vertex, then every vertex in this graph can reach all others.

To understand this statement, consider a boolean function $vis[x][y]$ to be true if reaching from vertex $x$ to $y$ is possible and denote the vertex specified above by '$1$'. Call the given directed graph be $G$ and consider another graph $G'$ which is reverse of $G$, that is $\forall$ edges $x \to y$ in $G$, there is corresponding edge $y \to x$ in $G'$. Point is that if $vis[1][k]$ is true $\forall$ $k \in [1,n]$ in $G$ as well as $G'$, then the answer is ``YES``. If not, then there exists a pair $(p,q)$ such that $vis[p][q]$ is false, even if previous condition holds. We have $vis[1][q]$ to be true in $G$. Since $vis[1][p]$ is true in $G'$, so $vis[p][1]$ would be true in $G$. Therefore, we can travel from $p$ to $q$ in $G$ (like $p \to 1 \to q$).  Contradiction! 

You can compute $vis[x][y]$ using DFS from node $1$. If you reach all nodes $x$ in both $G$ and $G'$, answer is ``YES``, else you can print ``1 x`` if you are running DFS on $G$, and ``x 1`` otherwise

### Sample Input

```text
4 6
1 2
2 1
1 3
2 3
3 4
4 3
```

### Sample Output

```text
NO
3 1
```

### Time Complexity

Analyse the time complexity of your Algorithm that you have used yourself :)
