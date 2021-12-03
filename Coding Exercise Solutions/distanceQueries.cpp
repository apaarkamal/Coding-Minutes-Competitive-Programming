#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>v,up;
vector<int>tin,tout,depth;
int level,timer;
void dfs(int x,int p,int d)
{
	tin[x]=++timer;
	up[x][0]=p;
	depth[x]=d;
	for(int i=1;i<=level;i++)
	{
		up[x][i]=up[up[x][i-1]][i-1];
	}
	for(auto itr:v[x])
	{
		if(itr!=p)
		{
			dfs(itr,x,d+1);
		}
	}
	tout[x]=++timer;
}
bool checker(int u,int v)
{
    return tin[u]<=tin[v] && tout[u]>=tout[v];
}
int lca(int u,int v)
{
	if(checker(u,v))
	{
		return u;
	}
	if(checker(v,u))
	{
		return v;
	}
	for(int i=level;i>=0;i--)
	{
		if(!checker(up[u][i],v))
		{
			u=up[u][i];
		}
	}
	return up[u][0];
}
vector<int> distanceQuery(int n, vector<vector<int>>edges, vector<vector<int>>queries)
{
	int x,y,val;
	level=ceil(log2(n));
	tin.resize(n+1);
	tout.resize(n+1,1e9);
	depth.resize(n+1);
	v=vector<vector<int>>(n+1,vector<int>());
	up.assign(n+1,vector<int>(level+1));
	for(int i=0;i<edges.size();i++)
	{
		x=edges[i][0],y=edges[i][1];
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,0,0);
	vector<int>ans;
	for(int i=0;i<queries.size();i++)
	{
	    x=queries[i][0],y=queries[i][1];
		val=lca(x,y);
		int value=depth[x]+depth[y]-2*depth[val];
	    ans.push_back(value);
	}
	return ans;
}