#include<bits/stdc++.h>
using namespace std;

// function to get the index with minimum value
int getMinIndex(vector<int> list){
    int minIndex = 0;
    for(int i = 0; i < list.size(); i++){
        if(list[i] < list[minIndex]){
            minIndex = i;
        }
    }
    return minIndex;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> price;          // vector of prices of each device
    vector<int> customer;       // vector of customers in the order they arrive
    bool bought[n];             // true if a device is sold

    for(int i = 0; i < n; i++){
        int p;
        cin >> p;
        price.push_back(p);
        bought[i] = false;
    }
    for(int i = 0; i < m; i++){
        int p;
        cin >> p;
        customer.push_back(p);
    }

    for(int i = 0; i < m; i++){
        
        int boughtIndex = getMinIndex(price);       // Index with minimum price
        for(int j = 0; j < n; j++){           
            if(price[j] > price[boughtIndex] && price[j] <= customer[i]){
                boughtIndex = j;
            }
        }

        // Now boughtIndex variable has the index of the 
        // price which is maximum among all those prices 
        // that are below the maximum price as told by customer

        if(!bought[boughtIndex]){           // Sold it to customer, if not bought already by someone else
            bought[boughtIndex] = true;
            customer[i] = price[boughtIndex];
        }
        else {          // else give -1 to customer
            customer[i] = -1;
        }
        /**
         * may be something is wrong here
         * Shouldn't the customer be given the second max price
         * that satisfies his conditions instead of -1 as done
         * in the else statement ?
         */
    }

    // Printing the output
    for(int i = 0; i < m; i++){
        cout << customer[i] << " ";
    }

}