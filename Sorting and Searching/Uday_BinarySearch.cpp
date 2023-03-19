#include <bits/stdc++.h>
using namespace std;
    int binary( int arr[] , int s, int e , int k){
        // if( s >= e) return -1;
        int mid = (s + e) /2;
        if(arr[mid] == k) return mid;
        if(s>=e) return -1;
        if ( k > arr[mid]){
            return binary(arr , mid+ 1, e, k);
        }
        else if( k < arr[mid] ){
            return binary(arr  , s , mid ,k);
        }
        return 0;
    }
    
    int binarysearch(int arr[], int n, int k) {
        return  binary( arr, 0 , n- 1 , k);
    }
    
int main()
{
    int arr1[] = {1 ,2, 3 ,4 ,5} ;
    int arr2[] = {11, 22, 33 ,44 ,55};
    cout << binarysearch( arr1 , 5, 4) << endl << binarysearch(  arr2 , 5 , 404) << endl;
    return 0;
}
