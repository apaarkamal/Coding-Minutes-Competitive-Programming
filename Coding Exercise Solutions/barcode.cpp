#include<bits/stdc++.h>
using namespace std;
#define inf 1e9

int solve(int n,int m,int x,int y, vector<vector<char>> grid){
    int cnt1=0,cnt2=0;
    vector<int>black(m+1),white(m+1);
    for(int i=0;i<m;i++)
    {
        cnt1=0,cnt2=0;
        for(int j=0;j<n;j++)
        {
            if(grid[j][i]=='.')
            {
                cnt1++;
            }
            else{
                cnt2++;
            }
        }
        white[i+1]=cnt1;
        black[i+1]=cnt2;
    }
    for(int i=1;i<=m;i++)
    {
        white[i]+=white[i-1];
        black[i]+=black[i-1];
    }
    vector<int>dp1(m+1,inf),dp2(m+1,inf);
    dp1[0]=dp2[0]=0;
    for(int i=1;i<=m;i++)
    {
        for(int j=x;j<=y;j++)
        {
            if(i-j>=0)
            {
                cnt1=black[i]-black[i-j];
                cnt2=white[i]-white[i-j];
                dp1[i]=min(dp1[i],dp2[i-j]+cnt1);
                dp2[i]=min(dp2[i],dp1[i-j]+cnt2);
            }
        }
    }
    int ans=min(dp1[m],dp2[m]);
    return ans;
}