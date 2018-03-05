# Depth-first search

## Description:

**Depth-first search _(DFS)_** is a simple traversing algorithm, which globally consists in two steps, that are going on and on, until all vertexes would be visited. (This time we will set it recursively)

At the start we have massive, array storing all vertices, where each vertex is associated with a color: white and black (in the begining all verticies are white) and our first vertex, which from we begin traversing(it's also white). 

First step, we check current vertex's color. If it's white, we proceed to the second step, else we end operation.

The second step, we make our vertex black and to each adjacent vertex use our function DFS.

Sometimes, there are 3 colors: white, black and __gray__. And it is used in the second part: firstly we make our vertex gray, than we ude finction DFS to all adjacent verticies and only than we make current vertex black. So, if you are not sure, that your algorithm will work - you can use 3 colors..

## Example:

### There is nodes: 
- **A**, that's connected with B and C

- **B**, that's connected with A and D

- **C**, that's connected with A, D and E

- **D**, that's connected with B, C and F

- **E**, that's connected with only C

- **F**, that's connected with only D

### Our Algorithm:

Array **colors**: 0, 0, 0, 0, 0, 0 (1st number - A's vertex color, 2nd number - B's vertex color e.t.c.)
> 0 means white and 1 means black;

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

![alt text](https://github.com/RuS2m/CODE/tree/master/DFS/DFS.gif "DFS")

