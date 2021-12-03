#include<bits/stdc++.h>
using namespace std;

bool check(long long x,long long y,long long p,long long q,long long val){
    return (p*val>=x) && (q*val- p*val>=y-x);
}

long long solve(int x,int y,int p,int q){
    int l=1,r=1e9,mid,ans;
    if(!check(x,y,p,q,r)){
        return -1;   
    }
    while(l<=r){
        mid=(l+r)/2;
        if(check(x,y,p,q,mid)){
            r=mid-1;
            ans=mid;
        }
        else{
            l=mid+1;
        }
    }
    long long total=(long long)q*(long long )ans;
    total-=y;
    return total;
}