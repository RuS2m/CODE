# Dijkstra's algorithm

## Problem statement:

Needs to find the shortest way from current vertex to all other.

## Description:

**Depth-first search _(DFS)_**  is an algorithm for finding the shortest paths between nodes in a graph.

At the start we have massive, array storing all unvisited vertices,ans massive, storing all vertices, where each vertex is associated with a number - path between current vertex and the other.

First step, we throw out our current vertex from unvisited vertices. Then we watch through all vertices unvisited adjacent to our vertex and calculate distance to them through current vertex. If it less, than make distance between start vertex to this vertex = new distance of path through current vertex. Then find there the vertex with the least path from start vertex to it.

The second step, then, we make our vertex - current. 

## Example:

### There are nodes: 
- **A**, that's connected with B and C

- **B**, that's connected with A and D

- **C**, that's connected with A, D and E

- **D**, that's connected with B, C and F

- **E**, that's connected with only C

- **F**, that's connected with only D

### Distances:
- AB = 1

- AC = 6

- BD = 1

- CD = 2

- CE = 3

- DF = 4
### Our Algorithm:

Array **not_visited**: A, B, C, D, E, F 
Array **distance**:

distance to | A | B | C | D | E | F
--- | --- | --- | --- | --- | --- | ---
length | 0 | inf | inf | inf | inf | inf

start vertex - A.
1. min distance from A to B = 1. min distance from A to C = 6. New start vertex - B.

distance to | A | B | C | D | E | F
--- | --- | --- | --- | --- | --- | ---
length | 0 | 1 | 6 | inf | inf | inf
```
(Array not_visited: B, C, D, E, F)
```
2. min distance from B to D = 1 => min distance from A to D = min distance from A to B + min distance from B to D = 1 + 1 = 2. New start vertex - D.

distance to | A | B | C | D | E | F
--- | --- | --- | --- | --- | --- | ---
length | 0 | 1 | 6 | 2 | inf | inf
```
(Array not_visited: C, D, E, F)
```
3. min distance from D to C = 2 => min distance from A to D = min from distance from A to C and min distance from A to D + min distance from D to C = min from 6 and 2 + 2 = min from 6 and 4 = 4. min distance from D to F = 4 => min distance from A to F = 6. New start vertex - C.

distance to | A | B | C | D | E | F
--- | --- | --- | --- | --- | --- | ---
length | 0 | 1 | ~~6~~ 4 | 2 | inf |68
```
(Array not_visited: C, E, F)
```
4. min distance from C to E = 3 => min distance from A to E = min distance from A to C + min distance from C to E = 4 + 3 = 7. New start vertex - E.

distance to | A | B | C | D | E | F
--- | --- | --- | --- | --- | --- | ---
length | 0 | 1 | 4 | 2 | 7 | 4
```
(Array not_visited: E, F)
```
5. E isn't connected with F

distance to | A | B | C | D | E | F
--- | --- | --- | --- | --- | --- | ---
length | 0 | 1 | 4 | 2 | 7 | 4
```
(Array not_visited: F)
```
7. All vertexes was visited => end


### Illustration:

![alt text](https://github.com/RuS2m/CODE/blob/master/Dijkstra/Dijkstra.gif)

