#include<bits/stdc++.h>
using namespace std;
#define inf 1e9

int minCost(int maxTime, vector<vector<int>> edges, vector<int> passingFees) {
    int n=passingFees.size();
    vector<vector<pair<int,int>>>v(n);
    for(int i=0;i<edges.size();i++)
    {
        int x=edges[i][0],y=edges[i][1],val=edges[i][2];
        v[x].push_back({y,val});
        v[y].push_back({x,val});
    }
    vector<vector<int>>dp(maxTime+1,vector<int>(n+1,inf));
    dp[0][0]=passingFees[0];
    int ans=inf;
    for(int i=0;i<=maxTime;i++)
    {
        for(int j=0;j<n;j++)
        {
            int cost=dp[i][j];
            if(cost==inf)
            {
                continue;
            }
            for(auto itr:v[j])
            {
                int x=itr.first,val;
                val=itr.second+i;
                if(val<=maxTime){
                    dp[val][x]=min(dp[val][x], cost+ passingFees[x]);
                }
            }
        }
    }
    for(int i=0;i<=maxTime;i++)
    {
        ans=min(ans,dp[i][n-1]);
    }
    return ans==inf?-1:ans;
}