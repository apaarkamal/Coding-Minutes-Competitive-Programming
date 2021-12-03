#include<bits/stdc++.h>
using namespace std;
#define maxn 524288

int seg[maxn];
void build(int v,int nl,int nr,int val, vector<int>&a)
{
    if(nl==nr)
    {
        seg[v]=a[nl];
    }   
    else
    {
        int mid=(nl+nr)/2;
        build(2*v,nl,mid,val-1,a);
        build(2*v+1,mid+1,nr,val-1,a);
        if(val%2==0)
        {
            seg[v]=seg[2*v]^seg[2*v+1];
        }   
        else
        {
            seg[v]=seg[2*v]|seg[2*v+1];
        }
    }
}
void update(int v,int nl,int nr ,int pos,int val,int cnt)
{
    if(nl==nr)
    {
        seg[v]=val;
    }
    else
    {
        int mid=(nl+nr)/2;
        if(pos<=mid)
        {
            update(2*v,nl,mid,pos,val,cnt-1);
        }
        else
        {
            update(2*v+1,mid+1,nr,pos,val,cnt-1);
        }

        if(cnt%2==0)
        {
            seg[v]=seg[2*v] ^ seg[2*v+1];
        }
        else
        {
            seg[v]=seg[2*v] | seg[2*v+1];
        }
    }
}

vector<int> solve(int n, vector<int>a, vector<vector<int>> queries){
    memset(seg,0,sizeof(seg));
    int val=pow(2,n);
    build(1,0,val-1,n,a);
    vector<int>ans;
    for(int i=0;i<queries.size();i++)
    {
        int x=queries[i][0],y=queries[i][1];
        update(1,0,val-1,x-1,y,n);
        ans.push_back(seg[1]);
    }
    return ans;
}