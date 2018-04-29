# Sorts

## Problem statement:

There is array and it's need to be sorted (made from the same elements, array, in which numbers are put in order from the smallest to the biggest one)

## Description:

### Max to end sort:

Make empty array, called **Answer** and make _operation_:
  1) take i-th element from the original array
  2) walk through **Answer** and stop at the element, which less, than current element, but the next element of **Answer's** array is more, than current element and add current element on place after element, we stopped.

And repeat this operation, while number of elements in **Answer** array will be the same, as in original one.

### Example:

There are **Array** and **Answer** arrays:
```
Array: 8 1 4 2 5 
Answer: -
```

#### Algorithm:

1. Add *8* to **Answer**
```
Array: 8 1 4 2 5
Answer: 8
```
2. Add *1* to **Answer**, before *8*
```
Array: 8 1 4 2 5
Answer: 1 8
```
3. Add *4* to **Answer**, before *8*, but after *1*
```
Array: 8 1 4 2 5
Answer: 1 4 8 
```
4. Add *2* to **Answer**, before *4*, but after *1*
```
Array: 8 1 4 2 5
Answer: 1 2 4 8
```
5. Add *5* to **Answer**, before *8*, but after *4*
```
Array: 8 1 4 2 5
Answer: 1 2 4 5 8
```
6. The answer is - **Answer**: 1 2 4 5 8

### Merge sort:

**TO DO:** [read materials](http://sorting.valemak.com/merge/)

### Example:
--
![sort_merge](https://github.com/RuS2m/CODE/blob/master/sorts/sort_merge.gif)

### Quick sort:

**TO DO:** [read materials](http://sorting.valemak.com/quick/)
### Example:
--
![sort_quick](https://github.com/RuS2m/CODE/blob/master/sorts/sort_quick.gif)

