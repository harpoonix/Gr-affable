# A Symphony of Algorithms

Before embarking upon our ambitious journey of programming algorithms for a self driving car, we first get a flavour of algorithmic time complexity, how it can be reduced and how redundant computations are avoided.

## The Problem

The problem essentially is to find the greatest sum of a subarray of the given array. The naive algorithm would loop through the array thrice : essentially finding all subarrays in two loops, and then a third to find the sum of values in the subarray. The following piece of code from `subarray_sum.cpp` illustrates the naive algortihm :

```cpp
int best_sum = 0;
for (int i=0; i<n; i++) {
    for (int j=i; j<n; j++) {
        int sum_of_this_subarray = 0;
        for (int k=i; k<=j; k++) {
            sum_of_this_subarray += array[k];
        }
        best_sum = max(best_sum, sum_of_this_subarray);
    }
}
```

## A Good First Issue

You can immediately notice that our algorithm performs, frankly terribly. We can eliminate some obvious redundant computations to reduce the complexity. Instead of computing the sum everytime we move the end index, we can compute the sum as we go along moving the end of the subarray. The following code illustrates this -

```cpp
int best_sum = 0;
for (int i=0; i<n; i++) {
    int sum_of_current_subarray = 0;
    for (int j=i; j<n; j++) { // Only need 2 loops now
        sum_of_current_subarray += array[j]; // Sum of the subarray starting at i and ending at j
        best_sum = max(best_sum, sum_of_current_subarray);
    }
}
```

That's some progress right there.

## Quest for Better Algorithms

We can create an $\mathcal{O}(n^2)$ algorithm by finding the maximum sum of a subarray that starts at a given index, say a. We then sum the values and move the right side of the subarray together.

Turns out, there's a way to solve the problem in $\mathcal{O}(n)$ time, traversing the array only once. The idea is to consider the maximum sum subarray that ends at an index $k$.

<details>
<summary> Hint </summary>
There are two possibilities-

1. The optimal subarray only contains the element at index $k$
2. The optimal subarray appends to the subarray of the element at index $k-1$

</details>
Work with the idea and optimise the solution to the fullest!
