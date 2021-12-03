#include<bits/stdc++.h>
using namespace std;

int solve(int n){
    vector<int>prime(n+1,1);
    for(int i=2;i*i<=n;i++){
        if(prime[i]){
            for(int j=i*i;j<=n;j+=i){
                prime[j]=0;
            }
        }
    }
    int ans=0;
    for(int i=3;i<=n-2;i++){
        if(prime[i]==1 && prime[i+2]==1){
            ans++;
        }
    }
    return ans;
}