#include<bits/stdc++.h>
using namespace std;

#define maxn 100001
int find(int x,vector<int>&visit)
{
    while(x!=visit[x])
    {
        return visit[x]=find(visit[x],visit);
    }
    return x;
}
void Union(int x,int y,vector<int>&visit,vector<int>&sz)
{
    int val=find(x,visit),val1=find(y,visit);
    if(val==val1)
    {
        return;
    }
    if(sz[val]>sz[val1])
    {
        swap(val,val1);
    }
    visit[val]=val1;
    sz[val1]+=sz[val];
}
vector<bool> DSU(vector<vector<int>>query)
{
    int n=query.size();
    vector<int>visit(maxn),sz(maxn,1);
    iota(visit.begin(),visit.end(),0);
    vector<bool>ans;
    for(int i=0;i<n;i++)
    {
        int x=query[i][0], u=query[i][1], v=query[i][2];
        if(x==1)
        {
            Union(u,v,visit,sz);
        }
        else{
            if(find(u,visit)==find(v,visit))
            {
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
    }
    return ans;
}