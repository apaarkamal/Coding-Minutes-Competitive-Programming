#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
 
long long power(long long a,int n){
    long long p;
    if(n==0)
    {
        return 1;
    }
    p=power(a,n/2);
    p=(p*p)%mod;
    if(n%2)
    {
        p=(p*a)%mod;
    }
    return p;
}
 
void update(int ind,int n,int val, vector<int>&bit){
    while(ind<=n){
        bit[ind]=(bit[ind]+val)%mod;
        ind+=ind&-ind;
    }
}
 
int get(int ind, vector<int>&bit){
    int ans=0;
    while(ind>0){
        ans=(ans+bit[ind])%mod;
        ind-=ind&-ind;
    }
    return ans;
}
 
int solve(int n,vector<int> a){
    vector<int>bit(n+1);
    map<int,int>mapping;
    for(int i=0;i<n;i++)
    {
        mapping[a[i]]=i;
    }
    int x=1;
    for(auto &itr:mapping)
    {
        itr.second=x++;
    }
    
    long long powers[n+1],modinv[n+1],inv=power(2,mod-2);
    powers[0]=1;
    modinv[0]=1;
    for(int i=1;i<=n;i++)
    {
        powers[i]=(powers[i-1]*2)%mod;
        modinv[i]=(modinv[i-1]*inv)%mod;
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        x=mapping[a[i]];
        long long val=(get(x,bit)*powers[i])%mod;
        ans=(ans+val)%mod;
        update(x,n,modinv[i+1],bit);
    }
    return ans;
}