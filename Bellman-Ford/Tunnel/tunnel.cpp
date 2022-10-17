#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    long long int *tunnel = new long long int[m];
    int *pair_start_end = new int[m][2];
    
    vector<int> score;
    for(int i = 0; i < m; i++){
    for(int j = 0; j < 2; j++){
        cin >> pair_start_end[i][j];
    } // paired up start and end arrays into multi-dimensional array
}
    int first = 1;
    int last = n;
    for(int i = 0; i < m; i++){
        if(start[i] == first){
            int sum = tunnel[i];
            int dest = end[i];
            while(dest!=last){
                for(int j = 0; j < m; j++){
                    if(start[j] == dest){
                        sum += tunnel[j];
                        dest = end[j];
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