#include<bits/stdc++.h>
using namespace std;

int minCut(string str) {
    int n;
    n=str.size();
    vector<vector<int>>pal(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        int x=i,y=i;
        while(x>=0 && y<n && str[x]==str[y])
        {
            pal[x][y]=1;
            x--;
            y++;
        }
    }
    for(int i=0;i<n-1;i++)
    {
        int x=i,y=i+1;
        while(x>=0 && y<n && str[x]==str[y])
        {
            pal[x][y]=1;
            x--;
            y++;
        }
    }
    vector<int>dp(n);
    for(int i=0;i<n;i++)
    {
        dp[i]=i;
    }
    for(int i=1;i<n;i++)
    {
        if(pal[0][i])
        {
            dp[i]=0;
        }
        for(int j=0;j<i;j++)
        {
            if(pal[j+1][i])
            {
                dp[i]=min(dp[i],dp[j]+1);
            }
        }
    }
    return dp[n-1];
}