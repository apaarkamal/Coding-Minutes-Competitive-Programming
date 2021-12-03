#include<bits/stdc++.h>
using namespace std;

int find(int x,vector<int>&visit)
{
    if(x!=visit[x])
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
        return ;
    }
    if(sz[val]>sz[val1])
    {
        swap(val,val1);
    }
    visit[val]=val1;
    sz[val1]+=sz[val];
}
int maxNumEdgesToRemove(int n, vector<vector<int>> edges) {
    vector<int>visit1(n+1),visit2(n+1),sz1(n+1,1),sz2(n+1,1);
    iota(visit1.begin(),visit1.end(),0);
    iota(visit2.begin(),visit2.end(),0);
    vector<pair<int,int>>v[3];
    for(int i=0;i<edges.size();i++)
    {
        int x=edges[i][1],y=edges[i][2],type=edges[i][0];
        v[type-1].push_back({x,y});
    }
    int ans=0;
    for(int i=0;i<v[2].size();i++)
    {
        int x=v[2][i].first,y=v[2][i].second;
        if(find(x,visit1)==find(y,visit1))
        {
            ans++;
            continue;
        }
        Union(x,y,visit1,sz1);
        Union(x,y,visit2,sz2);
    }
    for(int i=0;i<v[1].size();i++)
    {
        int x=v[1][i].first,y=v[1][i].second;
        if(find(x,visit2)==find(y,visit2))
        {
            ans++;
            continue;
        }
        Union(x,y,visit2,sz2);
    }
    for(int i=0;i<v[0].size();i++)
    {
        int x=v[0][i].first,y=v[0][i].second;
        if(find(x,visit1)==find(y,visit1))
        {
            ans++;
            continue;
        }
        Union(x,y,visit1,sz1);
    }
    if(sz1[find(1,visit1)]==n && sz2[find(1,visit2)]==n)
    {
        return ans;
    }
    return -1;
}