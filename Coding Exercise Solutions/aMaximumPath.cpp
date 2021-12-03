#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>v,up,maxi;
vector<int>in,out,depth;
int level,timer;
void dfs(int x,int p,int d, vector<int>&a)
{
    up[x][0]=p;
    depth[x]=d;
    in[x]=++timer;
    if(p!=0)
    {
        maxi[x][0]=max(a[x-1],a[p-1]);
    }
 
    for(int i=1;i<=level;i++)
    {
        up[x][i]=up[up[x][i-1]][i-1];
        maxi[x][i]=max(maxi[x][i-1],maxi[up[x][i-1]][i-1]);
    }
 
    for(auto itr:v[x])
    {
        if(itr!=p)
        {
            dfs(itr,x,d+1,a);
        }
    }
    out[x]=++timer;
}
bool is_ancestor(int u,int v)
{
    return in[u]<=in[v] && out[u]>=out[v];
}
int lca(int u,int v)
{
    if(is_ancestor(u,v))
    {
        return u;
    }
    if(is_ancestor(v,u))
    {
        return v;
    }
 
    for(int i=level;i>=0;i--)
    {
        if(!is_ancestor(up[u][i],v))
        {
            u=up[u][i];
        }
    }
    return up[u][0];
}
int solve(int u,int v,int anc, vector<int>&a)
{
    int val=a[u-1],val1=a[v-1];
    if(u!=anc)
    {
        for(int i=level;i>=0;i--)
        {
            if(depth[up[u][i]]>=depth[anc])
            {
                val=max(val,maxi[u][i]); 
                u=up[u][i];  
            }
        }
    }
    if(v!=anc)
    {
        for(int i=level;i>=0;i--)
        {
            if(depth[up[v][i]]>=depth[anc])
            {
                val1=max(val1,maxi[v][i]); 
                v=up[v][i];  
            }
        }
    }
    return max(val,val1);
}

vector<int> maximumPath (int n, vector<int> a, vector<vector<int>> edges, vector<vector<int>> queries)
{
    v=vector<vector<int>>(n+1,vector<int>());
    in= vector<int>(n+1,0);
    out= vector<int>(n+1, 1e9);
    timer=0;
    level=ceil(log2(n));
    up=vector<vector<int>>(n+1,vector<int>(level+1,0));
    depth=vector<int>(n+1,0);
    maxi=vector<vector<int>>(n+1,vector<int>(level+1,0));
    int x,y,val;
    for(int i=0;i<n-1;i++)
    {
        x=edges[i][0],y=edges[i][1];
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1,0,0,a);
    vector<int>ans;
    for(int i=0;i<queries.size();i++)
    {
        x=queries[i][0],y=queries[i][1];
        val=lca(x,y);
        ans.push_back(solve(x,y,val,a));
    }
    return ans;
}