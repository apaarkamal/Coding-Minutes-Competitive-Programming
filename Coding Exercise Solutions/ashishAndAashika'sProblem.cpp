#include<bits/stdc++.h>
using namespace std;
#define maxn 200001

long long bit[maxn];
long long sum(long long idx)
{
    long long ans=0;
    while(idx>0)
    {
        ans+=bit[idx];
        idx-=idx&-idx;
    }
    return ans;
}   
void update(long long x,long long val)
{
    while(x<maxn)
    {
        bit[x]+=val;
        x+=x&-x;
    }
}

long long solve(int n, vector<int> a ){
    memset(bit,0,sizeof(bit));
    vector<int>l(n),r(n);
    map<int,int>m;
    for(int i=0;i<n;i++)
    {
        m[a[i]]++;
        l[i]=m[a[i]];
    }
    m.clear();
    for(int i=n-1;i>=0;i--)
    {
        m[a[i]]++;
        r[i]=m[a[i]];
    }
    long long ans=0;
    for(int i=n-1;i>=0;i--)
    {
        long long x=sum(l[i]-1);
        ans+=x;
        update(r[i],1);
    }
    return ans;
}