#include<bits/stdc++.h>
using namespace std;

int maxProfit(int k, vector<int> prices) {
    int n=prices.size();
    if(n==0)
    {
        return 0;
    }
    int dp[k+1][n+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<n;j++)
        {
            dp[i][j]=dp[i][j-1];
            for(int k=0;k<j;k++)
            {
                dp[i][j]=max(dp[i][j], prices[j]-prices[k]+dp[i-1][k]);
            }
        }
    }
    return dp[k][n-1];
}