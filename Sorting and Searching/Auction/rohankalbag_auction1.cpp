#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> price;          // vector of prices of each device
    vector<int> customer;       // vector of customers in the order they arrive
    vector<bool> bought(n);     // true if a device is sold

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
    
    sort(price.begin(), price.end()); // O(log(n))

    //The overall complexity of the coming block is O(mn)
    for(int i=0;i<m;i++){
        //O(m)
        if(customer[i] < price[0]){
            //check if the budget is less than minimum price, if so ignore this customer
            customer[i] = -1;
            cout<<customer[i]<<endl;
            continue;
        }

        auto x = upper_bound(price.begin(), price.end(), customer[i]); //binary search O(log(n)) for the iterator to element > customer[i]
        int d = distance(price.begin(), x) - 1; //get distance of iterator from start //O(n)
        bool gotindex = false;
        
        while(d >= 0){
            //O(n)
            if(!bought[d]){
                //check if already bought
                customer[i] = price[d];
                bought[d] = true;
                gotindex = true;
                cout<<customer[i]<<endl;
                break;
            }
            else{
                //if not check for the previous smaller index
                d--;
            }
        }

        if(!gotindex){
            customer[i] = -1;
            cout<<customer[i]<<endl;
        }
    }
}