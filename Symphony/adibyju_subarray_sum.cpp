#include <iostream>
#include <algorithm>
#define vi vector<int>
using namespace std;

int max_subarray_sum(int *array, int n)
{
    // Iterate through all the elements of the array once
    // Time complexity: O(n) (Kadane's Algorithm)
    // Space complexity: O(1)
    int best_sum = array[0], sum_of_this_subarray = array[0];
    for (int i = 1; i < n; i++)
    {
        // sum_of_this_subarray stores maximum of subarray ending at array[i] or array[i]
        sum_of_this_subarray = max(sum_of_this_subarray + array[i], array[i]);

        // best_sum stores maximum of sum_of_this_subarray
        best_sum = max(best_sum, sum_of_this_subarray);
    }
    return best_sum;
}

int main()
{
    int n; // the number of elements in the array
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    cout << "The maximum sum of a subarray of the given array is " << max_subarray_sum(array, n) << endl;
}
