#include<bits/stdc++.h>
using namespace std;
#define maxn 200001
#define fi first
#define se second

int bit[maxn];
bool comp(pair<pair<int,int>,int>&p, pair<pair<int,int>,int>&p1)
{
    if(p.fi.se==p1.fi.se)
    {
        return p.fi.fi<p1.fi.fi;
    }
    return p.fi.se<p1.fi.se;
}
void update(int index,int val)
{
    while(index<maxn)
    {
        bit[index]+=val;
        index+=index&-index;
    }
}
int get(int index)
{
    int ans=0;
    while(index>0)
    {
        ans+=bit[index];
        index-=index&-index;
    }
    return ans;
}
vector<int> solve(int n, vector<int> c, vector<vector<int>> queries){
    memset(bit,0,sizeof(bit));
    int q=queries.size();
    pair<pair<int,int>,int>p[q];
    int x,y;
    for(int i=0;i<q;i++)
    {
        x=queries[i][0],y=queries[i][1];
        p[i].fi={x,y};
        p[i].se=i;
    }
    sort(p,p+q,comp);
    vector<int>ans(q);
    map<int,int>m;
    x=0;
    for(int i=0;i<n;i++)
    {
        if(m.find(c[i])!=m.end())
        {
            update(m[c[i]],-1);
        }
        m[c[i]]=i+1;
        update(m[c[i]],1);
        while(x<q && p[x].fi.se==i+1)
        {
            int val=get(p[x].fi.se)-get(p[x].fi.fi-1);
            ans[p[x].se]=val;
            x++;
        }
    }
    return ans;
}