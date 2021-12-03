#include<bits/stdc++.h>
using namespace std;
#define mod 998244353 
#define ll long long

ll power(ll a,ll n){
    ll p;
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

int NcR(int n,int r,vector<ll>&fact){
    ll total=fact[n];
    total=(total*power(fact[r],mod-2))%mod;
    total=(total*power(fact[n-r],mod-2))%mod;
    return total;
}

int solve(int n,int m){
    int ans=0;
    vector<ll>fact(m+1,1);
    for(int i=1;i<=m;i++){
        fact[i]=(fact[i-1]*i)%mod;
    }
    if(n>2){
        ans=((ll)NcR(m,n-1,fact)*power(2,n-3))%mod;
        ans=((ll)ans*(ll)(n-2))%mod;
    }
    return ans;
}
