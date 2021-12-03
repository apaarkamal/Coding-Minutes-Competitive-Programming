#include<bits/stdc++.h>
using namespace std;

int ans;
vector<int>sub;
vector<vector<int>> g;
 
void dfs(int k, int par)
{
	sub[k]=1;
	for(auto it:g[k])
	{
		if(it==par)
			continue;
		dfs(it, k);
		sub[k]+=sub[it];
	}
	if(sub[k]%2==0&&k!=1)
	{
		ans++;
	}
}
int solve(int n, vector<vector<int>> edges)
{
    ans=0;
    g=vector<vector<int>>(n+1,vector<int>());
    sub=vector<int>(n+1);
	for(int i=0;i<edges.size();i++)
	{
		int u=edges[i][0], v=edges[i][1];
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if(n%2)
	{
		return -1;
	}
	dfs(1, 1);
	return ans;
}