#include<bits/stdc++.h>
using namespace std;
#define maxn 100001

long long solve(int n, vector<int> a)
{
    vector<long long>dp(maxn),cnt(maxn);
    for(int i=0;i<n;i++)
    {
        cnt[a[i]]++;
    }
    dp[0]=0;
    dp[1]=cnt[1];
    long long ans=dp[1];
    for(int i=2;i<maxn;i++)
    {
        long long val=i*cnt[i];
        dp[i]=max(dp[i-1], val+dp[i-2]);
        ans=max(ans,dp[i]);
    }
    return ans;
}