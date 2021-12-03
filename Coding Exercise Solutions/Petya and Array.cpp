#include<bits/stdc++.h>
using namespace std;
#define maxn 100001
#define fi first 
#define se second 

int seg[4*maxn];
void update(int v,int l,int r,int val,int pos)
{
    if(l==r)
    {
        seg[v]=val;
        return;
    }
    int mid=(l+r)/2;
    if(pos<=mid)
    {
        update(2*v,l,mid,val,pos);
    }
    else{
        update(2*v+1,mid+1,r,val,pos);
    }
    seg[v]=seg[2*v]+seg[2*v+1];
}
int query(int v,int l,int r,int x,int y)
{
    if(y<x)
    {
        return 0;
    }
    if(x<=l && r<=y)
    {
        return seg[v];
    }
    int mid=(l+r)/2;
    return query(2*v,l,mid,x,min(y,mid))+query(2*v+1,mid+1,r,max(mid+1,x),y);
}
bool comp(const pair<long long,long long>&p ,const pair<long long, long long>&p1)
{
    if(p.fi==p1.fi)
    {
        return p.se<p1.se;
    }
    return p.fi<p1.fi;
}
long long solve(int n,long long t, vector<int>a){
    memset(seg,0,sizeof(seg));
    long long x,y,ans=0;
    vector<pair<long long,int>>v;
    vector<long long>pre(n+1);
    for(int i=0;i<n;i++)
    {
        pre[i+1]=pre[i]+a[i];
        x=pre[i+1];
        v.push_back({pre[i+1],i+1});
    }
    v.push_back({0,0});
    sort(v.begin(),v.end());
    for(int i=0;i<=n;i++)
    {
        x=pre[i]-t+1;
        y=lower_bound(v.begin(),v.end(),make_pair(x,-1),comp)-v.begin();
        ans+=query(1,0,n,y,n);
        y=lower_bound(v.begin(),v.end(),make_pair(pre[i],i),comp)-v.begin();
        update(1,0,n,1,y);
    }
    return ans;
}