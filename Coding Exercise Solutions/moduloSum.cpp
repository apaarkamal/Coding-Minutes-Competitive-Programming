#include<bits/stdc++.h>
using namespace std;

string solve(int n,int m,vector<int> a){
    if(n>m)
    {
        return "Yes";
    }
    vector<vector<bool>>dp(n,vector<bool>(m+1,false));
    dp[0][a[0]%m]=true;
    for(int i=1;i<n;i++)
    {
        int x=a[i]%m;
        dp[i][x]=true;
        for(int j=0;j<=m;j++)
        {
            int y=(x+j)%m;
            dp[i][j]=(dp[i-1][j] | dp[i][j]);
            dp[i][y]=(dp[i][y]  | dp[i-1][j] );
        }
    }
    
    if(dp[n-1][0])
    {
        return "Yes";
    }
    return "No";
}
