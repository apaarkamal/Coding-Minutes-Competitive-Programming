#include<bits/stdc++.h>
using namespace std;

bool validBfs(int n, vector<int> sequence , vector<vector<int>> edges){
    int x,y,val,val1;
    vector<vector<int>>v(n+1);
    vector<int>visit(n+1);
    for(int i=0;i<n-1;i++)
    {
        x=edges[i][0],y=edges[i][1];
        v[x].push_back(y);
        v[y].push_back(x);
    }
    queue<int>q;
    q.push(1);
    visit[1]=1;
    y=1;
    int flag=0;
    while(q.size())
    {
        x=q.front();
        q.pop();
        set<int>s;
        for(int i=0;i<v[x].size();i++)
        {
            val=v[x][i];
            if(visit[val]==0)
            {
                visit[val]=1;
                s.insert(val);
            }
        }
        val1=0;
        while(val1<s.size())
        {
            if(s.find(sequence[y])==s.end())
            {
                flag=1;
                break;
            }   
            q.push(sequence[y]);
            y++;
            val1++;
        }
    }
    return flag==1? false: true;
}