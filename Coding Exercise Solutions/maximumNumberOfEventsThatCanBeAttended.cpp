#include<bits/stdc++.h>
using namespace std;

bool comp(const vector<int>&a,const vector<int>&b)
{
    return a[1]<b[1];
}

int bs(int pos,int val,vector<int>&end)
{
    int l=0,r=pos,mid,ans=-1;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(end[mid]<val)
        {
            ans=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    return ans;
}
int maxValue(vector<vector<int>> events, int k) {
    int n=events.size();
    sort(events.begin(),events.end(),comp);
    vector<int>end(n);
    for(int i=0;i<n;i++)
    {
        end[i]=events[i][1];
    }
    vector<vector<int>>dp(n+1,vector<int>(k+1,0));
    dp[0][0]=events[0][2];
    for(int i=1;i<n;i++)
    {
        dp[i][0]=max(dp[i-1][0],events[i][2]);
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<k;j++)
        {
            int pos=bs(i-1,events[i][0],end);
            dp[i][j]=max(dp[i][j],dp[i-1][j]);
            if(pos!=-1)
            {
                dp[i][j]=max(dp[i][j],dp[pos][j-1]+events[i][2]);
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++)
        {
            ans=max(ans,dp[i][j]);
        }
    }
    return ans;
}