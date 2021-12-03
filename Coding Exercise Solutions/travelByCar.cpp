#include<bits/stdc++.h>
using namespace std;
#define inf 1e9

vector<int> travelByCar(int n,int l, vector<vector<int>>edges ,vector<vector<int>> queries)
{
    vector<vector<int>>dis(n+1,vector<int>(n+1,inf)),fuel(n+1,vector<int>(n+1,inf));
    int x,y,val;
    for(int i=0;i<edges.size();i++)
    {
        x=edges[i][0],y=edges[i][1],val=edges[i][2];
        x--;
        y--;
        dis[x][x]=0;
        dis[y][y]=0;
        fuel[x][x]=0;
        fuel[y][y]=0;
        dis[x][y]=val;
        dis[y][x]=val;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                if(dis[j][k]>dis[j][i]+dis[i][k])
                {
                    dis[j][k]=dis[j][i]+dis[i][k];
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            {
                continue;
            }
            if(dis[i][j]<=l)
            {
                fuel[i][j]=1;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                if(fuel[j][k]>fuel[j][i]+fuel[i][k])
                {
                    fuel[j][k]=fuel[j][i]+fuel[i][k];
                }
            }
        }
    }
    vector<int>ans;
    for(int i=0;i<queries.size();i++)
    {
        x=queries[i][0],y=queries[i][1];
        x--;
        y--;
        if(fuel[x][y]==inf)
        {
            ans.push_back(-1);
        }
        else{
            ans.push_back(fuel[x][y]-1);
        }
    }
    return ans;
}