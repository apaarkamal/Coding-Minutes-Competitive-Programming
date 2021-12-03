#include<bits/stdc++.h>
using namespace std;

int trie[3000001][2],node;
void insert(int x)
{
    int val=0,flag,val1;
    for(int i=30;i>=0;i--)
    {
        val1=1<<i;
        flag=0;
        if(x&val1)
        {
            flag=1;
        }
        if(!trie[val][flag])
        {
            trie[val][flag]=++node;
        }
        val=trie[val][flag];
    }
}
int find(int x)
{
    int ans=0,val=0,val1,flag;
    for(int i=30;i>=0;i--)
    {
        val1=1<<i;
        flag=0;
        if(x&val1)
        {
            flag=1;
        }
        if(trie[val][flag^1])
        {
            ans+=val1;
            val=trie[val][flag^1];
        }
        else{
            val=trie[val][flag];
        }
    }
    return ans;
}
vector<int> maximizeXor(vector<int> nums, vector<vector<int>> queries) {
    node=0;
    memset(trie,0,sizeof(trie));
    vector<pair<pair<int,int>,int>>v;
    vector<int>ans(queries.size(),-1);
    for(int i=0;i<queries.size();i++)
    {
        v.push_back({{queries[i][1],queries[i][0]},i});
    }
    sort(v.begin(),v.end());
    sort(nums.begin(),nums.end());
    int x,y,n=nums.size();
    x=0;
    for(int i=0;i<v.size();i++)
    {
        y=v[i].first.first;
        while(x<n && nums[x]<=y)
        {
            insert(nums[x]);
            x++;
        }
        if(x==0)
        {
            continue;   
        }
        ans[v[i].second]=find(v[i].first.second);
    }
    return ans;    
}