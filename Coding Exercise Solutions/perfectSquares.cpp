#include<bits/stdc++.h>
using namespace std;
#define maxn 1e9

int numSquares(int n) {
    vector<int>dp(n+1,maxn);
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        int x=sqrt(i);
        for(int j=1;j<=x;j++)
        {
            int y=j*j;
            if(i-y>=0)
            {
                dp[i]=min(dp[i],dp[i-y]+1);
            }
        }
    }
    return dp[n];
}