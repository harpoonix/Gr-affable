#include <iostream>

using namespace std;
long long maxSubarraySum(int arr[], int n){
         long long sum = 0;
         long long maxi = 0;
         long long max_element = -1e9;
        for(int i = 0 ; i< n ; i++){
            sum += arr[i];
            if( arr[i] > max_element){
                max_element = arr[i];
            }
            maxi = max(maxi , sum);
            if( sum  < 0 ) sum = 0;
        }
        return maxi>0 ? maxi : max_element;
}
int main()
{
    int Arr[] = {1,2,3,-2,5};
    int n =  sizeof(Arr) /  sizeof(Arr[0]);
    cout<< maxSubarraySum(Arr , n );
    return 0;
}
