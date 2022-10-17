# Grid Ways

As part of the navigating system, sometimes you need to know just how many paths there are from point A to point B, and not just the shortest. When some route is blocked by an unforseen construction activity, you often need to reroute. Roads are a dynamic scene, and your planned route could end up obstructed. In such cases it is rather helpful to know the total number of possible paths.

We can model a simple starting version of the above problem as follows.

You are given an $n\times n$ grid, whose squares may have holes, and thus can't be driven over. You can only move right or down.
Find the number of ways you can go from the top left square to the bottom right square, without falling into holes.

## Input

The first input line has an integer $n$: the size of the grid.  
After this, there are $n$ lines that describe the grid. Each line has n characters: `.` denotes an empty cell, and `*` denotes a hole.  

### Example

Input  
10
.*......*.
...*...*..
......*...
...*.*....
....*.....
..*..*....
..*.......
....*..*..
*........*
....*.....  

Output  
344
