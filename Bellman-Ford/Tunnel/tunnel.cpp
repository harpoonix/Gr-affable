// #include<bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    long long int *tunnel = new long long int[m];
    int start, end;
    vector<pair<int, int>> edge;
    vector<int> score;
    for(int i = 0; i < m; i++){
        cin >> start >> end >> tunnel[i];
        edge.push_back(make_pair(start, end));
    }
    int first = 1;
    int last = n;
    for(int i = 0; i < m; i++){
        if(edge[i].first == first){
            int sum = tunnel[i];
            int dest = edge[i].second;
            while(dest!=last){
                for(int j = 0; j < m; j++){
                    if(edge[j].first == dest){
                        sum += tunnel[j];
                        dest = edge[j].second;
                        break;
                    }
                }
            }
            score.push_back(sum);
        } 
    }
    int max = score[0];
    for(int i = 0; i < score.size(); i++){
        if(score[i] > max) max = score[i];
    }
    cout << max << endl;
}

// Problems in above code :
// - Very very inefficient
// - will not work if stuck in a loop, like n = 6, 1->3 3->5 5->2 2->3
// - Time complexity high
// - Wrong answers for large inputs
// - Does not take account that we can go into a same tunnel several times
// Hint : Bellman Ford!!! 