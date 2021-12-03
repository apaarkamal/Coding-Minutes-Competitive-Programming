#include<bits/stdc++.h>
using namespace std;
#define maxn 16385
#define inf 1e9

int n,dp[15][maxn];
int solve(int pos,int mask,vector<int>&a,vector<int>&b)
{
    if(pos==n)
    {
        return mask==0?0:inf;
    }
    if(dp[pos][mask]!=-1)
    {
        return dp[pos][mask];
    }
    int ans=inf;
    for(int i=0;i<n;i++)
    {
        int val=1<<i;
        if(mask&val)
        {
            ans=min(ans, (a[pos]^b[i])  + solve(pos+1,mask^val,a,b));
        }
    }
    return dp[pos][mask]=ans;
}
int minimumXORSum(vector<int> nums1, vector<int> nums2) {
    n=nums1.size();
    memset(dp,-1,sizeof(dp));
    int val=1<<n;
    val--;
    int ans=inf;
    ans=solve(0,val,nums1,nums2);
    return ans;
}