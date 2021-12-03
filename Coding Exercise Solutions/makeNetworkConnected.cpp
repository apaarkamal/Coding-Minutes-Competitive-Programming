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
        return;
    }
    if(sz[val]>sz[val1])
    {
        swap(val,val1);
    }
    visit[val]=val1;
    sz[val1]+=sz[val];
}
int makeConnected(int n, vector<vector<int>> connections) {
    vector<int>visit(n),sz(n);
    iota(visit.begin(),visit.end(),0);
    sz.assign(n,1);
    int cnt=0,extra=0;
    for(int i=0;i<connections.size();i++)
    {
        int x=connections[i][0],y=connections[i][1];
        if(find(x,visit)==find(y,visit))
        {
            extra++;
            continue;
        }
        Union(x,y,visit,sz);
    }
    for(int i=0;i<n;i++)
    {
        if(find(i,visit)==i)
        {
            cnt++;
        }
    }
    return cnt-1<=extra?cnt-1:-1;
}