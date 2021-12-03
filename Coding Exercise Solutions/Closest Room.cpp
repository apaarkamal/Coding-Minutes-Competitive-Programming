#include<bits/stdc++.h>
using namespace std;

bool comp(const vector<int>&a,const vector<int>&b)
{
    return a[1]>b[1];
}

vector<int> closestRoom(vector<vector<int>> rooms, vector<vector<int>> queries) {
    int n=rooms.size();
    sort(rooms.begin(),rooms.end(),comp);
    vector<vector<int>>q;
    int ptr=0,m=queries.size();
    vector<int>ans(m,-1);
    for(int i=0;i<m;i++)
    {
        int x=queries[i][0],y=queries[i][1];
        q.push_back({x,y,i});
    }
    sort(q.begin(),q.end(),comp);
    set<int>s;

    for(int i=0;i<m;i++)
    {
        while(ptr<n && rooms[ptr][1]>=q[i][1])
        {
            s.insert(rooms[ptr][0]);
            ptr++;
        }
        int x,val,y=1e9,pos=1e9;
        if(s.size())
        {
            auto itr=s.lower_bound(q[i][0]);
            if(itr!=s.end())
            {
                x=*itr;
                val=abs(q[i][0]-x);
                if(val<=y)
                {
                    if(val==y)
                    {
                        pos=min(pos,x);
                    }
                    else{
                        pos=x;
                    }
                    y=val;
                }
            }
            itr=s.upper_bound(q[i][0]);
            if(itr!=s.begin())
            {
                itr--;
                x=*itr;
                val=abs(q[i][0]-x);
                if(val<=y)
                {
                    if(val==y){
                        pos=min(pos,x);
                    }
                    else{
                        pos=x;
                    }
                    y=val;
                }
            }
            ans[q[i][2]]=pos;
        }
    }
    return ans;
}