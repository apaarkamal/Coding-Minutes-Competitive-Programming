#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define maxn 150001

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
    int ans=1;
    vector<ll>fact(maxn,1);
    for(int i=1;i<maxn;i++){
        fact[i]=(fact[i-1]*(ll)i)%mod;
    }
    map<int,int>primes;
    for(int i=2;i<=sqrt(m);i++){
        while(m%i==0){
            primes[i]++;
            m/=i;
        }
    }
    if(m>1){
        primes[m]++;
    }
    for(auto itr:primes){
        ans=((ll)ans*(ll)NcR(n+itr.second-1,n-1,fact))%mod;
    }
    return ans;
}