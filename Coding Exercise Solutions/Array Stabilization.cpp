#include<bits/stdc++.h>
using namespace std;

vector<int>seg;
void build(int v,int l,int r,vector<int>&a){
    if(l==r)
    {
        seg[v]=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*v,l,mid,a);
    build(2*v+1,mid+1,r,a);
    seg[v]=__gcd(seg[2*v],seg[2*v+1]);
}
int query(int v,int l,int r,int x,int y)
{
    if(y<x)
    {
        return 0;
    }
    if(x<=l && y>=r)
    {
        return seg[v];
    }
    int mid=(l+r)/2;
    return __gcd(query(2*v,l,mid,x,min(mid,y)), query(2*v+1,mid+1,r,max(x,mid+1),y));
}
int solve(int n, vector<int>a){
    vector<int>arr(2*n);
    seg=vector<int>(8*n+1);
    for(int i=0;i<n;i++)
    {
        arr[i]=a[i];
        arr[i+n]=a[i];
    }
    build(1,0,2*n-1,arr);
    int l=0,r=n,mid,ans;
    while(l<=r)
    {
        mid=(l+r)/2;
        int flag=1,x=query(1,0,2*n-1,0,mid);
        for(int i=1;i<n;i++)
        {
            int y=query(1,0,2*n-1,i,i+mid);
            if(y!=x)
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            r=mid-1;
            ans=mid;
        }
        else{
            l=mid+1;
        }
    }
    return ans;
}