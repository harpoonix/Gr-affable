#include <iostream>
#include <algorithm>
#define vi vector<int>
using namespace std;

int max_subarray_sum(int *array, int n) {
    // Go through all possible subarays
    // Maintain a maximum of their sum, return the maximum
    int best_sum = 0;
    for (int i=0; i<n; i++) {
        int sum_of_this_subarray = 0;
        for (int j=i; j<n; j++) {
            sum_of_this_subarray += array[j];
            best_sum = max(best_sum, sum_of_this_subarray);
        }
    }
    return best_sum;
}

int main(){
    int n; // the number of elements in the array
    cin >> n;
    int array[n];
    for (int i=0; i<n; i++) {
        cin>>array[i];
    }
    cout<<"The maximum sum of a subarray of the given array is "<< max_subarray_sum(array, n) << endl;
}
