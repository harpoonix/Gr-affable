#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<string> maze(n);
    cin.ignore();
    for(int i=0;i<n;i++){
        getline(cin, maze[i]);
    }
    
    //dynamic programming approach to solve this problem
    //bottoms up approach
    vector<vector<int>> dp(n, vector<int>(n, 0));
    if(maze[0][0] == '.')
        dp[0][0] = 1;

    //column 1
    for(int i=1;i<n;i++){
        if(maze[i][0] == '.')
            dp[i][0] = dp[i-1][0];
    }

    //row 1
    for(int i=1;i<n;i++){
        if(maze[0][i] == '.')
            dp[0][i] = dp[0][i-1];
    }

    //using recurrance relation

    for(int i = 1; i<n; i++){
        for(int j = 1; j<n; j++){
            if(maze[i][j] != '*'){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }

    cout<<dp[n-1][n-1]<<endl;
    
}