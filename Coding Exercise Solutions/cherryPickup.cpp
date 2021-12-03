#include<bits/stdc++.h>
using namespace std;

int dy[4]={-1,0,1};
int solve(int r,int c1,int c2,int n,int m,vector<vector<int>>&a,vector<vector<vector<int>>>&dp)
{
    if(r<0 || c1<0 || c2<0 || r>=n || c1>=m || c2>=m)
    {
        return 0;
    }
    if(dp[r][c1][c2]!=-1)
    {
        return dp[r][c1][c2];
    }
    int ans=0,val=a[r][c1];
    if(c1!=c2)
    {
        val+=a[r][c2];
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            ans=max(ans,val+solve(r+1, c1+dy[i], c2+dy[j],n,m ,a,dp));
        }
    }
    return dp[r][c1][c2]=ans;
}
int cherryPickup(vector<vector<int>> grid) {
    int n=grid.size(),m=grid[0].size();
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(m+1,-1)));
    return solve(0,0,m-1,n,m,grid,dp);
}