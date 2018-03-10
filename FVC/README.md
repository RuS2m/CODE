# The Forest vertex-cover problem

## Problem statement:

Original problem sounds like: 
    There is connected graph. You can remove vertexes. Which the least set of vertexes you can leave, that each edge of the graph is incident to at least one of remaining vertexes.

    Here we have not a connected graph, we have set of connected graphs (forest)

## Description:

This problem is NP-hard, so there are no fast methods, that can predict current result... So we desry aproximation algorithm. It can find vertex-cover with size not exceeding the original one in two times.

Firstly, we have array with all edges and answer array - array with verticies from vertex-cover. In the loop, while there will be no elements in edges array, we take random element from array with edges and take vertex, which incident to this edge. Then we delete all edges from array, which are connected wit this vertex, and add it to answer-arrray.. Then do it again and again, and by the end, in the answer array we will have our vertex-cover array.

## Example:

### There are nodes:

- **A**, that's connected with B and C
 
- **B**, that's connected with A and D
  
- **C**, that's connected with A, D and E
    
- **D**, that's connected with B, C and F
    
- **E**, that's connected with only C
  
- **F**, that's connected with only D
    
### Our AlgorithmL

Array **answer**: -

1.

2.

![alt text](https://github.com/RuS2m/CODE/blob/master/FVC/fvc.jpg "FVC")
