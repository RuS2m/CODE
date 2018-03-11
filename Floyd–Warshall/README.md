# Floyd–Warshall algorithm

## Problem statement:

Finding shortest paths in a weighted graph with positive or negative edge weights (but with no negative cycles)

## Description:

This is the simpliest way to find the shortesr way, and by virtue of simplicity it's complexity equals _O(n^3)_.

The algorithm is just search of all cases and looks like this:
```
for k = 1 to n //перебор всех вершин (k)
    for i = 1 to n //смотрим для каждой пар вершин i и j
        for j = 1 to n //проход через вершину
            W[i][j] = min(W[i][j], W[i][k] + W[k][j]) //если меньше - заменяем.
```
