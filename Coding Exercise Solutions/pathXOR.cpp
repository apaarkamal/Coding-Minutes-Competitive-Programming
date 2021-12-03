#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>v,up;
vector<int>tin,tout,pre;
int level,timer;
void dfs(int x,int p,int w,vector<int>& a)
{
    tin[x]=++timer;
    up[x][0]=p;
    pre[x]=w^pre[p];
    for(int i=1;i<=level;i++)
    {
        up[x][i]=up[up[x][i-1]][i-1];
    }
    for(auto itr:v[x])
    {
        if(itr!=p)
        {
            dfs(itr,x,a[itr-1],a);
        }
    }
    tout[x]=++timer;
}
bool is_ancestor(int u, int v)
{
    return tin[u]<=tin[v] && tout[u]>=tout[v];
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
vector<int> pathXor(int n, vector<int> a, vector<vector<int>> edges, vector<vector<int>> queries){
    
    tin.assign(n+1,-1);
    tout.assign(n+1,1e9);
    v=vector<vector<int>>(n+1,vector<int>());
    pre.resize(n+1);
    level=ceil(log2(n));
    up.assign(n+1,vector<int>(level+1));
    int x,y,val;
    for(int i=0;i<edges.size();i++)
    {
        x=edges[i][0],y=edges[i][1];
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1,0,a[0],a);
    vector<int>ans;
    for(int i=0;i<queries.size();i++)
    {
        x=queries[i][0],y=queries[i][1];
        val=lca(x,y);
        int value=pre[x]^pre[y]^a[val-1];
        ans.push_back(value);
    }

    return ans;
}