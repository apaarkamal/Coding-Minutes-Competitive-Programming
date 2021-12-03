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

int solve(int n){
    int ans=1;
    long long x=power(26,mod-2);
    long long y=(2*power(25,mod-2))%mod;
    y=(y*(1+mod-power(x,n/2)))%mod;
    ans=(ans+y)%mod;
    if(n%2==0){
        ans=(ans+mod-power(x,n/2))%mod;
    }
    return ans;
}

