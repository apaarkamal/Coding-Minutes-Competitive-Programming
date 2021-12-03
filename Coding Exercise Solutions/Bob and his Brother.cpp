#include<bits/stdc++.h>
using namespace std;
#define inf 1e18

long long check(vector<int>&a ,vector<int>&b, int x){
    long long cnt=0;
    for(auto itr:a){
        if(itr>x){
            break;
        }
        cnt+=abs(itr-x);
    }
    for(int i=b.size()-1;i>=0;i--){
        if(b[i]<x){
            break;
        }
        cnt+=abs(b[i]-x);
    }
    return cnt;
}

long long solve(int n,int m,vector<int> a, vector<int> b){
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int l=1,r=1e9,mid1,mid2;
    long long ans=inf;
    while(l<=r){
        mid1=l+(r-l)/3;
        mid2=r-(r-l)/3;
        long long x=check(a,b,mid1);
        long long y=check(a,b,mid2);
        if(x<y){
            r=mid2-1;
        }
        else
        if(x>y){
            l=mid1+1;
        }
        else{
            ans=min(ans,x);
            l=mid1+1;
            r=mid2-1;
        }
    }
    return ans;
}
