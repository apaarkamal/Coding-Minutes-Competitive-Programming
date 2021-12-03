#include<bits/stdc++.h>
using namespace std;

void dfs(int x,int p, vector<int>&sub, vector<vector<int>>&v)
{
    sub[x]=1;
    for(auto itr:v[x])
    {
        if(itr!=p)
        {
            dfs(itr,x,sub,v);
            sub[x]+=sub[itr];
        }
    }
}
vector<int> subtreeProblem (int n, vector<vector<int>> edges, vector<int> queries)
{
    vector<int>sub(n+1);
    vector<vector<int>>v(n+1);
    int x,y;
    for(int i=0;i<edges.size();i++)
    {
        x=edges[i][0],y=edges[i][1];
        v[x].push_back(y);
        v[y].push_back(x);
    }
    vector<int>ans;
    dfs(1,-1,sub,v);
    for(int i=0;i<queries.size();i++)
    {
        x=queries[i];
        ans.push_back(sub[x]);
    }
    return ans;
}