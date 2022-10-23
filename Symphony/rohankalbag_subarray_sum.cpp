#include <iostream>
#include <algorithm>
#include <vector>
#define vi vector<int>
using namespace std;

int max_subarray_sum(vi array, int n) {
    // Go through all possible subarays
    // Maintain a maximum of their sum, return the maximum
    // Implement using Kadane's Algorithm for O(n)
    int best_sum = 0, curr_sum = 0;
    for(int i=0; i<n; i++) {
        curr_sum += array[i];
        if(curr_sum > best_sum){
            //check if curr sum is larger than the best sum
            //if so change it
            best_sum = curr_sum;
        }
        //curr sum can be negative if array[i] was negative
        curr_sum = curr_sum < 0 ? 0 : curr_sum; 
    }
    return best_sum;
}

int main(){
    int n; // the number of elements in the array
    cin >> n;
    vi array(n); //using vector as more versatile than int array 
    for (int i=0; i<n; i++) {
        cin>>array[i];
    }
    cout<<"The maximum sum of a subarray of the given array is "<< max_subarray_sum(array, n) << endl;
}
