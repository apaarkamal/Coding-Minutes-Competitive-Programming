#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

long long power(long long a,int n){
    long long p;
    if(n==0){
        return 1;
    }
    p=power(a,n/2);
    p=(p*p)%mod;
    if(n%2){
        p=(p*a)%mod;
    }
    return p;
}

int solve(int n,vector<int> a){
    vector<int>ans(n);
    sort(a.begin(),a.end(),greater<int>());
    ans[0]=a[0];
    ans[1]=a[1];
    for(long long i=2;i<n;i++){
        long long val=(i*(i+1))/2;
        val=val%mod;
        val=power(val,mod-2);
        ans[i]=(((1-val)*(long long)ans[i-1])%mod+mod)%mod;
        ans[i]=(ans[i]+ (val*(long long)a[i])%mod)%mod;
    }
    return ans[n-1];
}