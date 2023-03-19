#include <iostream>
#include <algorithm>
#define vi vector<int>
using namespace std;

int max_subarray_sum(int *array, int n) {
    // Go through all possible subarays
    // Maintain a maximum of their sum, return the maximum
    int best_sum = 0;
	int sum = 0;
	for (int k = 0; k < n; k++) {
		sum = max(array[k],sum+array[k]);
		best_sum = max(best_sum,sum);
	}
	// for (int i=0; i<n; i++) {
	//     for (int j=i; j<n; j++) {
	//         int sum_of_this_subarray = 0;
	//         for (int k=i; k<=j; k++) {
	//             sum_of_this_subarray += array[k];
	//         }
	//         best_sum = max(best_sum, sum_of_this_subarray);
	//     }
	// }
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
