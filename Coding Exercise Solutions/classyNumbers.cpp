#include<bits/stdc++.h>
using namespace std;
#define maxn 19
long long dp[2][maxn][maxn];
vector<int>v;

long long cal(int pos,int fl,int cnt)
{
    if (pos==v.size())
    {
        return (cnt<=3);
    }
    if(dp[fl][pos][cnt]!=-1)
    {
        return dp[fl][pos][cnt];
    }
    int limit=9;
    if(!fl)
    {
        limit=v[pos];
    }
    long long ans=0;
    for(int i=0;i<=limit;i++)
    {
        int flag=(i<v[pos]);
        ans+=cal(pos+1,fl|flag,cnt+(i!=0));
    }
    return dp[fl][pos][cnt]=ans;
}

long long solve(long long L, long long R){
    v.clear();
    long long x=R;
    while(x!=0)
    {
        v.push_back(x%10);
        x/=10;
    }
    memset(dp,-1,sizeof(dp));
    reverse(v.begin(),v.end());
    long long ans=cal(0,0,0);
    v.clear();
    x=L-1;
    while(x!=0)
    {
        v.push_back(x%10);
        x/=10;
    }
    memset(dp,-1,sizeof(dp));
    reverse(v.begin(),v.end());
    ans-=cal(0,0,0);
    return ans;
}