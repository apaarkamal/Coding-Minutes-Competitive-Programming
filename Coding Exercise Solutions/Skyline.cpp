#include<bits/stdc++.h>
using namespace std;
#define mod 1000000

int solve(int n){
    vector<vector<int>>precomp(n+1,vector<int>(n+1));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=i;j++){
            if(j==0){
                precomp[i][j]=1;
            }
            else{
                precomp[i][j]=(precomp[i-1][j]+precomp[i][j-1])%mod;
            }
        }
    }
    return precomp[n][n];
}