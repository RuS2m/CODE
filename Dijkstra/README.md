# Dijkstra's algorithm

## Problem statement:

Needs to find the shortest way from current vertex to all other.

## Description:

**Depth-first search _(DFS)_**  is an algorithm for finding the shortest paths between nodes in a graph.

At the start we have massive, array storing all unvisited vertices,ans massive, storing all vertices, where each vertex is associated with a number - path between current vertex and the other.

First step, we throw out our current vertex from unvisited vertices. Then we watch through all vertices unvisited adjacent to our vertex and find there the vertex vertex with the least path to it.

The second step, then, we make our vertex - current. And find the path length to it - minimum of path length from all adjacent verticies + path length from adjacent verticies to current. 

## Example:

### There is nodes: 
- **A**, that's connected with B and C

- **B**, that's connected with A and D

- **C**, that's connected with A, D and E

- **D**, that's connected with B, C and F

- **E**, that's connected with only C

- **F**, that's connected with only D

### Distances:
- AB = ...

- AC = ...

- BD = ...

- CD = ...

- CE = ...

- DF = ...
### Our Algorithm:

Array **not_visited**: A, B, C, D, E, F 
Array **distance**:

  | A | B | C | D | E | F
--- | --- | --- | --- | --- | --- | ---
A | 0 | . | . | . | . | .
B | . | 0 | . | . | . | .
C | . | . | 0 | . | . | .
D | . | . | . | 0 | . | .
E | . | . | . | . | 0 | .
F | . | . | . | . | . | 0

1. A becomes black
```
(Array colors: 1, 0, 0, 0, 0, 0)
```
2. B becomes black
```
(Array colors: 1, 1, 0, 0, 0, 0)
```
3. D becomes black
```
(Array colors: 1, 1, 0, 1, 0, 0)
```
4. F becomes black
```
(Array colors: 1, 1, 0, 1, 0, 1)
```
5. C becomes black
```
(Array colors: 1, 1, 1 , 1, 0, 1)
```
6. E becomes black
```
(Array colors: 1, 1, 1, 1, 1, 1)
```
7. All vertexes are black => end


### Illustration:

![alt text](https://github.com/RuS2m/CODE/blob/master/Dijkstra/Dijkstra.gif)

