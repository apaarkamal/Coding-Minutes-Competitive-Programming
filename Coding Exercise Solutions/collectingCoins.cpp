#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> matrix) {
    int n=matrix.size();
    if(n==0)
    {
        return 0;
    }
    int m=matrix[0].size();
    vector<vector<int>>dp(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i==0 && j==0)
            {
                dp[i][j]=matrix[i][j];
            }
            else{
                int x=i-1>=0?dp[i-1][j]:0;
                int y=j-1>=0?dp[i][j-1]:0;
                dp[i][j]=matrix[i][j]+max(x,y);
            }
        }
    }
    return dp[n-1][m-1];
}