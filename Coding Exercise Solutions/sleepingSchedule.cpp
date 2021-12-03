#include<bits/stdc++.h>
using namespace std;

int solve(int n, int h,int l, int r, vector<int> a){
    vector<vector<int>>dp(n+1,vector<int>(h,-1));
    dp[0][0]=0;
    for(int i=0;i<n;i++)
    {
        int x=a[i];
        for(int j=0;j<h;j++)
        {
            if(dp[i][j]!=-1)
            {
                int val=(x+j)%h;
                dp[i+1][val]=max(dp[i+1][val],dp[i][j]+(l<=val && r>=val));
                val=(x-1+j)%h;
                dp[i+1][val]=max(dp[i+1][val],dp[i][j]+(l<=val && r>=val));
            }
        }
    }
    int ans=0;
    for(int i=0;i<h;i++)
    {
        ans=max(ans,dp[n][i]);
    }
    return ans;
}