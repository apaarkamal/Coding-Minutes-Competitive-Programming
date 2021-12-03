#include<bits/stdc++.h>
using namespace std;

vector<int>marked,sz;
int find(int x)
{
    if(marked[x]!=x)
    {
        return marked[x]=find(marked[x]);
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
    marked[val]=val1;
    sz[val1]+=sz[val];
}
int specialPath(int n, vector<int> a, vector<vector<int>> edges,int start, int end)
{
    int x,y,val,flag;
    int l=1,r=1e9,mid,ans=1e9;  
    marked=vector<int>(n+1);
    while(l<=r)
    {
        mid=(l+r)/2;
        iota(marked.begin(),marked.end(),0);
        sz.assign(n+1,1);
        for(int i=0;i<edges.size();i++)
        {
            x=edges[i][0],y=edges[i][1];
            x--;
            y--;
            val=abs(a[x]-a[y]);
            if(val<=mid)
            {
                Union(x+1,y+1);
            }
        }
        flag=find(start)==find(end)?1:0;
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