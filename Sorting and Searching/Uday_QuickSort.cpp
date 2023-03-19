#include <iostream>
using namespace std;

int partition( int arr[], int s , int e){
    int pivot = arr[s];
    int cnt = 0;
    for(int i =  s + 1 ; i<= e ; i++){
        if( arr[i] <= pivot)cnt++;
    }
    int pivotInd = s + cnt;
    swap( arr[s] , arr[pivotInd]);
    int i = s;
    int j = e;
    while( i <pivotInd && j > pivotInd){
        while( arr[i] <= pivot ) i++;
        while( arr[j]> pivot) j--;
        if( i  < pivotInd && j > pivotInd) swap( arr[i++] , arr[j--]);
    }
    return pivotInd;
}

void quicksort( int arr[] , int s , int e){
    if( s >= e ) return;
    int pivotInd = partition(arr, s, e);
    quicksort( arr , s, pivotInd - 1);
    quicksort( arr , pivotInd +1 , e);
}

int main()
{
    int arr[] = {1 ,3, 4, 2, 8,5 ,6,9 ,7, 10};
    quicksort( arr, 0 , 9);
    for(auto it : arr){
        cout << it << " " ;
    }
    return 0;
}
