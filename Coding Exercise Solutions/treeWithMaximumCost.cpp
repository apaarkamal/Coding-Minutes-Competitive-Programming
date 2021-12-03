#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>v;
vector<long long>sub,dp,ans;
void dfs_1(int x,int p,vector<int> a)
{
    sub[x]=a[x-1];
    for(auto itr:v[x])
    {
        if(itr!=p)
        {
            dfs_1(itr,x,a);
            sub[x]+=sub[itr];
            dp[x]+=dp[itr]+sub[itr];
        }
    }
}
void dfs(int x,int p)
{
    long long par;
    if(p!=0)
    {
        par=ans[p]-dp[x]-sub[x];
        ans[x]=par+dp[x]+sub[1]-sub[x];
    }   
    for(auto itr:v[x])
    {
        if(itr!=p)
        {
            dfs(itr,x);
        }
    }
}
long long treeMaxCost(int n, vector<int> a ,vector<vector<int>> edges)
{
    v=vector<vector<int>>(n+1,vector<int>());
    sub.assign(n+1,0);
    ans.assign(n+1,0);
    dp.assign(n+1,0);
    long long x,y,val;
    for(int i=0;i<n-1;i++)
    {
        x=edges[i][0],y=edges[i][1];
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs_1(1,0,a);
    ans[1]=dp[1];
    dfs(1,0);
    val=0;
    for(int i=1;i<=n;i++)
    {
        val=max(val,ans[i]);
    }
    return val;
}