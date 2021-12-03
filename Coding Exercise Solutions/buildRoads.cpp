#include<bits/stdc++.h>
using namespace std;
#define maxn 100001
#define pb push_back
vector<int>par(maxn),sz(maxn,1);
int find(int x)
{
    if(x!=par[x])
    {
        return par[x]=find(par[x]);
    }
    return x;
}
void Union(int x,int y)
{
    int val=find(x),val1=find(y);
    if(val==val1)
    {
        return;
    }
    if(sz[val]>sz[val1])
    {
        swap(val,val1);
    }
    par[val]=val1;
    sz[val1]+=sz[val];
}
long long buildRoads(vector<vector<long long>>Coordinates){
    int n=Coordinates.size();
    long long p,q;
    iota(par.begin(),par.end(),0);
    sz.assign(maxn,1);
    vector<array<long long,2>>x,y;
    for(long long i=0;i<n;i++)
    {
        p=Coordinates[i][0],q=Coordinates[i][1];
        x.pb({p,i});
        y.pb({q,i});
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    vector<array<long long,3>>edges;
    for(int i=1;i<n;i++)
    {
        p=x[i-1][1];
        q=x[i][1];
        edges.pb({x[i][0]-x[i-1][0],p,q});
    }
    for(int i=1;i<n;i++)
    {
        p=y[i-1][1];
        q=y[i][1];
        edges.pb({y[i][0]-y[i-1][0],p,q});
    }
    sort(edges.begin(),edges.end());
    long long ans=0;
    for(int i=0;i<edges.size();i++)
    {
        p=edges[i][1];
        q=edges[i][2];
        if(find(p)!=find(q))
        {
            Union(p,q);
            ans+=edges[i][0];
        }
    }
    return ans;
}