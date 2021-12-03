#include<bits/stdc++.h>
using namespace std;
#define maxn 1024
#define mod 1000000007

long long dp[40][maxn];
vector<vector<int>>v;
int solve(int hat,int mask)
{
    if(hat>=40)
    {
        return mask==0;
    }
    if(dp[hat][mask]!=-1)
    {
        return dp[hat][mask];
    }
    long long ans=0,x,val;
    ans=(ans+solve(hat+1,mask))%mod;
    for(int i=0;i<v[hat].size();i++)
    {
        x=v[hat][i];
        val=1<<x;
        if(mask&val)
        {
            ans=(ans+solve(hat+1,mask^val))%mod;
        }
    }
    return dp[hat][mask]=ans;
}
int numberWays(vector<vector<int>> hats) {
    v.resize(40);
    int n=hats.size();
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<hats.size();i++)
    {
        for(auto itr:hats[i])
        {
            v[--itr].push_back(i);
        }
    }
    int val=1<<n;
    val--;
    return solve(0,val);
}