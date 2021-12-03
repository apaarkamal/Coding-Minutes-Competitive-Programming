#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

long long dp[101][201],n;
long long solve(int pos,int finish,int fuel,vector<int>&a)
{
    if(fuel<0)
    {
        return 0;
    }
    if(dp[pos][fuel]!=-1)
    {
        return dp[pos][fuel];
    }
    long long ans=(pos==finish);
    for(int i=0;i<n;i++)
    {
        if(i!=pos)
        {
            ans=(ans+solve(i,finish,fuel-abs(a[i]-a[pos]),a))%mod;
        }
    }
    return dp[pos][fuel]=ans;
}
int countRoutes(vector<int> locations, int start, int finish, int fuel) {
    memset(dp,-1,sizeof(dp));
    n=locations.size();
    return solve(start,finish,fuel,locations);
}