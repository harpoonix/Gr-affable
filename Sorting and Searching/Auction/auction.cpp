#include<iostream>
#include<vector>
using namespace std;

// function to get the index with minimum value


int main(){
    int n, m;
    cin >> n >> m;
            // vector of prices of each device
     multiset<int> price;
    vector<int> customer(m);
    for(int i =0 ;i<n;i++){
        int x;
        cin >> x;
        price.insert(x);
    }
    for(int i = 0;i<m;i++){
        int u;
        cin >> u;
       auto it =  price.lower_bound(u);
       if(it == price.end()){
          customer[i] = -1;
       }
       else{
        customer[i] = *it;
        price.erase(it);
       }

    }
    for(auto i : customer)cout << i <<" ";
        return 0;


     

                              // vector of customers in the order they arrive
    
}