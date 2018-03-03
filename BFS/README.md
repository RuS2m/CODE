# Breadth-first search

## Problem statement:

--
## Description:

**Breadth-first search _(BFS)_** is a simple traversing algorithm, which globally consists in two steps, that are going on and on, until all vertexes would be visited. At the start we have massive, array storing vertices, that we must visit and our first vertex, which from we begin traversing(and it contatins in our array). First step, we must achieve, is move from our vertex to adjacent and add it to our array.. and we will visit all our start vertex's neighbours the same way(with adding to array). The second step, we must achieve, is to delete our start vertex from array and assign new first element of array as start vertex...(than, after we count all start vertex's neighbores, on the second step, we will take new start vertex and add its neighboures e.t.c)
So as not be confused because of which nodes were visited, and which won't, we can create new array, that contain all vertexes, that we have never used before... And when it became empty, we will end our algorithm.

--
## Example:

### There is nodes: 
- **A**, that's connected with B and C

- **B**, that's connected with A and D

- **C**, that's connected with A, D and E

- **D**, that's connected with B, C and F

- **E**, that's connected with only C

- **F**, that's connected with only D

### Our Algorithm:

1. Visit B, delete B from *not_used* array, add B to *must_visit* array

2. Visit C, delete C from *not_used* array, add C to *must_visit* array

3. Delete A from *must_visit* array

4. Visit D, delete D from *not_used* array, add D to *must_used* array

5. Delete B from *must_visit* array

6. Visit E, delete E from *not_used* array, add E to *must_used* array

7. Delete C from *must_visit* array

8. Visit F, delete F from *not_used* array, add F to *must_used* array

9. Delete D from *must_visit* array

10. Delete E from *must_visit* array

11. Delete F from *must_visit* array

12. *must_visit* array is empty => END

--
