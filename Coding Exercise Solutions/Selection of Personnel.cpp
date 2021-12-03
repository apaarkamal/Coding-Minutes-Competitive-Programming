#include<bits/stdc++.h>
using namespace std;

long long solve(int n){
    vector<vector<long long>>precomp(n+1,vector<long long>(n+1,1));   
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            precomp[i][j]=precomp[i-1][j-1]+precomp[i-1][j];
        }
    }
    long long ans=precomp[n][5]+precomp[n][6]+precomp[n][7];
    return ans;
}