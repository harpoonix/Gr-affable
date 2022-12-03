#include <iostream>
#include <algorithm>
#define vi vector<int>
using namespace std;
#include<bits/stdc++.h>
using namespace std;

int max_subarray_sum(int a[], int size)
{
    int x = INT_MIN, y = 0;
 
    for (int i = 0; i < size; i++) {
        y = y + a[i];
        if (x < y)
            x = y;
 
        if (y < 0)
            y = 0;
    }
    return x;
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