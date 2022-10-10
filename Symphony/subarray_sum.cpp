#include <iostream>
#include <algorithm>
#define vi vector<int>
using namespace std;

int max_subarray_sum(int *array, int n) {
    // Go through all possible subarays
    // Maintain a maximum of their sum, return the maximum
    int best = 0, sum = 0;
    for (int k=0;k<n;k++){
        sum = max(array[k],sum+array[k]);
        best = max(best,sum);
    }
    cout<<best;
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
