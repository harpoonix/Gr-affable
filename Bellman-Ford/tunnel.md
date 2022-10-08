# Tunnels

Lets play a game of Tunnels. Suppose there are $n$ stations and $m$ tunnels between them. We enumerate stations by integers $1$ to $n$ and you have to travel from station $1$ to $n$. Your initial score in this game is zero. Each time you pass though a tunnel, it adds an integer to your score(Note that integer means it may be negative as well). You have to find the maximum score that you can achieve during your journey from station $1$ to $n$, given that you can travel through a tunnel as many times as you want.

A file ``tunnel.cpp`` is given here which has a very inefficient solution to this problem. You have to modify that code to achieve the goal of the problem efficiently. The idea is to use Bellman Ford!

## Input
There are $m + 1$ lines in input. The first line has two integers $n$ and $m$. The rest $m$ lines give the information about the tunnels. Each line has three integers $x, y, z$ representing that a tunnel starts from station $x$, ends at station $y$ and adds $z$ to your score. Note that all tunnels are one way.

## Output
Print the maximum score that you can achieve. If you can get an arbitrarily large score, print ``INF``.


