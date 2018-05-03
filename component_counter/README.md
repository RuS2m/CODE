# The number of connected components

## Problem statement:

There is random graph, and you should find out number of сonnected components in it - (number of subgraphs, in which any two vertices are connected to each other by paths and and which is connected to no additional vertices in the supergraph)

## Description:

We use DFS (Depth-first search) in our algorithm, and you can watch in in this repository.

Firstly (how we did it in DFS algorithm) initialize a **colour** array, were all verexes have clour zero. Then, we search through all vertexes and if vertex's colour is zero, we run our DFS algorithm, starting from this vertex, were all vertexes in connected component turns to colour 1, and increase our component counter by 1. After we walk through all vertexes, we got exact answer in our variable of component counter. 

