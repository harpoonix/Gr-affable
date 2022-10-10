# Closest Points

Our goal is to find the closest pair of points among the $n$ given points.

## The Problem

Find the smallest distance between a pair of two (different) points.
The distance $d$ between a two points $(x_1, y_1)$ and $(x_2, y_2)$ is $d = \sqrt{(x_1-x_2)^2 + (y_1-y_2)^2}$.  
The naive algorithm with $\mathcal{O}(n^2)$ running time iterates through all pairs of points, and finds the closest one. Time is of the essence though, and we can't afford this slackness. We have to find an $\mathcal{O}(n \log n)$ implementation.

## Working Idea

We will try to solve this using the divide and conquer paradigm. 
We can split the given $n$ points by an appropriately chosen vertical line into two halves $S_1$ and $S_2$ of size $n/2$. (for simplicity in explaining the idea, assume the points to have different $x$ coordinates).  
The idea is to split the problem into smaller ones, and combine the results in some manner.
We can then make two recursive calls to `closest_pair` on the sets $S_1$ and $S_2$, say the distances returned are $d_1$ and $d_2$.
The smallest distance will be the minimum of $d \equiv min(d_1, d_2)$ and the least distance $D$ between the pair of points $p_1$ and $p_2$ such that they belong to different halves $S_1$ and $S_2$.  
We cannot check for all $(p_1, p_2) \in S_1 \times S_2$, this operation is of quadratic complexity.

Think of how you can narrow down your search for cross-half pairs that might result in smaller distance than $d$.

## Hints

Which are the pairs of points the distance between which is **surely** greater than $d$? They could be a certain distance apart on the $x$ axis.
A good place to start looking for optimum pairs $(p_1, p_2)$ would be to discard all such points.

<details>
  <summary>Elementary filter</summary>
  Any point whose x-distance from the middle line is greater than d can be discarded. Why?
</details>

Note that even this filter, by itself could result in an $n^2$ naive search. We need to build up on the idea to get a linear algorithm to parse through the pairs.
 