#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>adj;
void dfs1(int nd , int pr, vector<int>&dp1, vector<int>&a)
{
	dp1[nd] = a[nd-1] == 1 ? 1 : -1;
 
	for (auto ch : adj[nd])
	{
		if (ch == pr)
			continue;
 
		dfs1(ch, nd,dp1,a );
		dp1[nd] += max(0, dp1[ch]);
	}
}
 
void dfs2(int nd, int pr ,vector<int> &dp2, vector<int>&dp1)
{
	dp2[nd] = dp1[nd];
 
	if (pr)
	{
		int val = dp2[pr] - max(0, dp1[nd]);
		dp2[nd] += max(0, val);
	}
 
	for (auto ch : adj[nd])
	{
		if (ch == pr)
			continue;
 
		dfs2(ch, nd,dp2,dp1);
	}
}

vector<int> maxWhiteSubtree(int n, vector<int> a, vector<vector<int>> edges)
{
    adj=vector<vector<int>>(n+1,vector<int>());
    vector<int>dp1(n+1),dp2(n+1);
    vector<int>ans;
    int x,y;
	for (int i = 0; i < n - 1; ++i)
	{
		x=edges[i][0],y=edges[i][1];
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
 
	dfs1(1,0,dp1,a);
	dfs2(1,0,dp2,dp1);
 
	for(int i=1;i<=n;i++)
	{
	    ans.push_back(dp2[i]);
	}
	return ans;
 
}