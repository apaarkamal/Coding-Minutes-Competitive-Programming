#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
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

bool check(int sum,int a,int b){
    while(sum!=0){
        if(sum%10!=a && sum%10!=b){
            return false;
        }
        sum/=10;
    }
    return true;
}

int solve(int a,int b,int n){
    int ans=0,sum=0;
    ll fact[n+1];
    fact[0]=1;
    for(int i=1;i<=n;i++){
        fact[i]=(fact[i-1]*(ll)i)%mod;
    }
    for(int i=0;i<=n;i++){
        sum=(a*i)+ ((n-i)*b);
        if(check(sum,a,b)){
            ll cal=fact[n];
            cal=(cal*power(fact[i],mod-2))%mod;
            cal=(cal*power(fact[n-i],mod-2))%mod;
            ans=(ans+cal)%mod;
        }
    }
    return ans;
}
