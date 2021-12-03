#include<bits/stdc++.h>
using namespace std;
#define inf 1e9
#define fi first
#define se second

vector<int>solve(int n, int m, vector<vector<int>>road){
    int x,y,val;
    vector<vector<pair<int,int>>>v(n+1);
    for(int i=0;i<m;i++)
    {
        x=road[i][0],y=road[i][1],val=road[i][2];
        v[x].push_back({y,val});
    }
    vector<int>ans(n,inf);
    for(int i=1;i<=n;i++)
    {
        vector<int>dis(n+1,inf);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>q;
        q.push({0,i});
        int flag=1;
        val=inf;
        while(q.size())
        {
            pair<int,int>p=q.top();
            q.pop();
            for(auto itr:v[p.se])
            {
                x=itr.fi,y=itr.se;
                if(x==i)
                {
                    val=min(val,y+p.fi);
                }
                if(dis[x]>p.fi+y)
                {
                    dis[x]=p.fi+y;
                    q.push({dis[x],x});
                }
            }
        }
        ans[i-1]=val==inf?-1:val;
    }
    return ans;
}