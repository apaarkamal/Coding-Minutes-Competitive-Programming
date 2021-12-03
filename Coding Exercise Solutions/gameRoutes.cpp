#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007 

int gameRoutes(int n, vector<vector<int>> teleporters)
{
    long long x,y;
    vector<vector<int>>v(n+1);
    vector<int>ind(n+1);
    vector<long long>dp(n+1);
    for(int i=0;i<teleporters.size();i++)
    {
        x=teleporters[i][0],y=teleporters[i][1];
        v[x].push_back(y);
        ind[y]++;
    }
    queue<int>q;
    vector<int>topo;
    for(int i=1;i<=n;i++)
    {
        if(ind[i]==0)
        {
            q.push(i);
        }
    }
    while(q.size())
    {
        x=q.front();
        q.pop();
        topo.push_back(x);
        for(auto itr:v[x])
        {
            ind[itr]--;
            if(ind[itr]==0)
            {
                q.push(itr);
            }
        }
    }
    dp[1]=1;
    for(auto itr:topo)
    {
        for(auto it:v[itr])
        {
            dp[it]=(dp[it]+dp[itr])%mod;
        }
    }
    return dp[n];
}