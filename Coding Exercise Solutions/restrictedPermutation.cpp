#include<bits/stdc++.h>
using namespace std;

vector<int> solve(int n,int m, vector<vector<int>> arr)
{
    vector<vector<int>>v(n+1);
    vector<int>in(n+1);
    int x,y;
    for(int i=0;i<m;i++)
    {
        x=arr[i][0],y=arr[i][1];
        v[x].push_back(y);
        v[y].push_back(x);
        in[y]++;
    }
    set<int>s;
    vector<int>topo;
    for(int i=1;i<=n;i++)
    {
        if(in[i]==0)
        {
            s.insert(i);
        }
    }
    while(s.size())
    {
        x=*s.begin();
        s.erase(x);
        topo.push_back(x);
        for(auto itr:v[x])
        {
            in[itr]--;
            if(in[itr]==0)
            {
                s.insert(itr);
            }
        }
    }
    vector<int>ans;
    if(topo.size()==n)
    {
        ans=topo;
    }
    return ans;
}