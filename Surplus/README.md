# The Surplus

We have been optimising the heck out of our self-driving algorithms, and our endeavours have bore fruit: we have saved quite a lot on energy costs, and route computation costs.  
Alas, times are tough, and funding for the project is hard to come by. Apprehensive of the government cutting down your budget citing too generous of an amount being given, you decide to spend your surplus.

## What is a Surplus?

A most important question! I'm glad you asked! I'll let [Oscar](https://theoffice.fandom.com/wiki/Oscar_Martinez) from [The Office](https://www.imdb.com/title/tt0386676/) explain the concept [impeccably](https://www.youtube.com/watch?v=dWfrMMNeK2k).  

Now that you know what a surplus is, you make an impish call. At the next trial run, you decide to go along the longest possible path from the starting point. The test route is known to have no cycles, so you can't just go around in circles. We know beforehand that the test route can be modelled as a [tree](https://en.wikipedia.org/wiki/Tree_(graph_theory)).  
The next trial will involve multiple test runs, each starting at some node of the tree. You don't know which point your car can be assigned to start from, so you decide to compute *for all nodes* the length of longest path that starts at that particular node.

Can you compute for every node, the longest path length that begins at that node in $\mathcal{O}(n)$ time?

## Hints

A good starting point for traversing trees is to root the tree arbitrarily. The longest length path will either go through one of the children of this node or through the parent of this node. Try and see if dynamic programming can help you with this.

Recall that in dynamic programming, we exploit the optimal substructure of a problem. This happens if the optimal solution to a problem can be obtained by using optimal solutions of its subproblems.  
Longest path length going through the children of the node - is just 1 added to the maximum of the longest path lengths of its children. A more challenging version of this idea can be used for the parent case.

We chose to root the tree (even if its arbitrary) so we could use this optimal child-parent substructure.
