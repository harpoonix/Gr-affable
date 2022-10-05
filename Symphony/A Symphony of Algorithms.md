# A Symphony of Algorithms

## The Problem

The problem essentially is to find the greatest sum of a subarray of the given array. The naive algorithm would loop through the array thrice : essentially finding all subarrays in two loops, and then a third to find the sum of values in the subarray. The following piece of code illustrates the naive algortihm : 

```cpp
int best = 0;
for (int a = 0; a < n; a++) {
	for (int b = a; b < n; b++) {
		int sum = 0;
		for (int k = a; k <= b; k++) {
			sum += array[k];
		}
		best = max(best,sum);
	}
}
``` 

We can create an $\mathcal{O}(n^2)$ algorithm by finding the maximum sum of a subarray that starts at a given index, say a. We then sum the values and move the right side of the subarray together.
