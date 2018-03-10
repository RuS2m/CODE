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


```
(Array answer: -)
(Array with edges: AB, AC, BD, CD, CE, DF)
```
### Our Algorithm:

Array **answer**: -

1. We chose edge AB. A become element in answer array. From array  we delete edges: AB and AC.

```
(Array answer: A)
(Array with edges: BD, CD, CE, DF)
``` 

2. We chose edge BD. B become element in answer array. From array  we delete edges: BD.

 ```
 (Array answer: A, B)
 (Array with edges: CD, CE, DF)
 ```

3. We chose edge CD. C become element in answer array. From array  we delete edges: CD and CE.

 ```
  (Array answer: A, B, C)
   (Array with edges: DF)
```

4. We chose edge DF. B become element in answer array. From array  we delete edges: DF.

 ```
  (Array answer: A, B, C, D)
   (Array with edges: -)
```

5. Answer - array{A, B, C, D}

![alt text](https://github.com/RuS2m/CODE/blob/master/FVC/fvc.jpg "FVC")
