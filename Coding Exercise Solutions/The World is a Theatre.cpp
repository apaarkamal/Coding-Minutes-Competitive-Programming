#include<bits/stdc++.h>
using namespace std;
#define maxn 31

long long solve(int n,int m,int t){
    vector<vector<long long>>precomp(maxn,vector<long long>(maxn,1));
    for(int i=1;i<maxn;i++){
        for(int j=1;j<i;j++){
            precomp[i][j]=precomp[i-1][j-1]+precomp[i-1][j];
        }
    }
    long long ans=0;
    for(int i=4;i<=t-1;i++){
        int x=i,y=t-i;
        if(x<=n && y<=m)
            ans+=precomp[n][x]*precomp[m][y];
    }
    return ans;
}