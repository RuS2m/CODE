# Kruskal's algorithm

## Problem statement:

There is random connected weighted graph and you need to find a minimum-spanning-tree. Kruskal's algorithm is one of most efficient algorithm to solve this problem.

## Description:

As it was already said, Kruskal is prety efficient and it's really finds that spanning-tree, that wee actually need (it finds minimum of all.. there is no aproximation)

Algorithm consists from only one repeating operation. Firslty we initialize empty array, where we will keep edges from our minimum-spanning-tree. Than, we repeat this operation, while we can: we from all edges, that not create cycle, find minimum-weighted one and add that to our massive.

When algorithm stops, in our array left all edges of the exact wanted spanning-tree.

## Example:

### There are nodes:

- **A**: that's connected with B (AB = 7) and D (AD = 5)

- **B**: that's connected with A (AB = 7), C (BC = 8), D (BD = 9) and E (BE = 7)

- **C**: that's connected with B (BC =  8) and E (CE = 5)

- **D**: that's connected with A (AD = 5), B (BD = 9), E (DE = 15) and F (DF = 6)

- **E**: that's connected with B (BE = 7), C (CE = 5), D (DE = 15) and F (EF = 8)

- **F**: that's connected with D (DF = 6), E (EF = 8) and G (FG = 11)

- **G**: that's connected with E (EG = 9) and F (FG = 11)

![example](https://github.com/RuS2m/CODE/blob/master/Kruskal/example.png)

**List of all edges:**

```
AB = 7, AD = 5, BC = 8, BD = 9, BE = 7, CE = 5, DE = 15, DF = 6, EF = 8, FG = 11
```

### Algorithm:

Array **answer**: -

1. We choose edge AD, because that's minimum-weighted edge with weight = 5:

```
answer: AD
```

2. We choose edge CE, because that's minimum-weighted edge with weight = 5 and it's not create cycle in graph:

```
answer: AD, CE
```

3. We choose edge DF, because that's minimum-weighted edge with weight = 6 and it's not create cycle in graph:

```
answer: AD, CE, DF
```

4. We choose edge BE, because that's minimum-weighted edge with weight = 7 and it's not create cycle in graph (AB = 7, but that create a cycle ABD):

```
answer: AD, CE, DF, BE
```

5. We choose edge EG, because that's minimum-weighted edge with weight = 9 and it's not create cycle in graph:

```
answer: AD, CE, DF, BE, EG
```

6. Algorithms ands and answer is graph with edges {AD, CE, BE, EG}

![Kruskal](https://github.com/RuS2m/CODE/blob/master/Kruskal/Kruskal.gif)
