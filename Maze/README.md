# The Maze

You (our hero) has a most important occasion to attend - against all odds, you've landed yourself a date!
Your date has chosen to meet at a fancy restaurant on the other side of the town - the roads of where you haven't roamed. You take out a map of the city, and the whole thing looks like a giant maze. After all, cities are like giant mazes. You can only drive along roads (gatekeeping much, huh?).  
Keen to impress your date, you decide to arrive in style - in your own self-driving car! But no one likes to [figure out mazes](https://aryamanmaithani.github.io/worse-maze/), certainly not you when you're short on time.

The Geolocation subsystem of our self driving car has pioneered an amazing technology. Through GPS satellites, your car can been fed a map of the city.  
You realise you'd rather code an algorithm to find the shortest (also, :) valid) route from point A to B on the map instead of banging on head against the dead end of mazes.  
You saw an [ingenious way](https://twitter.com/matthen2/status/1440443280827699206) to solve mazes and as a programmer, thought if this could help you. Or does it simply count toward procrastination?

## The Problem

You are given the map of a city, your task is to find a path from start to the end. You can move left, right, up, down.  
The first input line has two integers n and m: the height and width of the map.

Then there are n lines of m characters describing the map. Each character is . (road), # (buildings, lawns, etc. Do NOT drive over these), A (start), or B (end). There is exactly one A and one B in the input.

First print "YES", if there is a path, and "NO" otherwise.

If there is a path, print the length of the shortest such path and its description as a string consisting of characters L (left), R (right), U (up), and D (down). You can print any valid solution.
