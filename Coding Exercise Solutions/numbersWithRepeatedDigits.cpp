#include<bits/stdc++.h>
using namespace std;

vector<int>v;
int dp[2][10][1024],len;
int solve(int pos,int flag,int mask)
{
    if(pos==len)
    {
        return 1;
    }
    if(dp[flag][pos][mask]!=-1)
    {
        return dp[flag][pos][mask];
    }
    int limit=9;
    if(!flag)
    {
        limit=v[pos];
    }
    int ans=0;
    for(int i=(pos==0);i<=limit;i++)
    {
        int fl=0;
        if(i<v[pos])
        {
            fl=1;
        }
        int newmask=mask;
        int valid=mask&(1<<i);
        if(valid){
            newmask=newmask^(1<<i);
            ans+=solve(pos+1,flag|fl,newmask);
        }
    }
    return dp[flag][pos][mask]=ans;
}
int numDupDigitsAtMostN(int n) {
    string str=to_string(n);
    int ans=0;
    v.clear();
    for(int i=1;i<str.size();i++)
    {
        memset(dp,-1,sizeof(dp));
        v.push_back(9);
        len=i;
        ans+=solve(0,0,1023);
    }
    v.clear();
    int x=n;
    while(x!=0)
    {
        v.push_back(x%10);
        x/=10;
    }
    len=str.size();
    reverse(v.begin(),v.end());
    memset(dp,-1,sizeof(dp));
    ans+=solve(0,0,1023);
    return n-ans;
}