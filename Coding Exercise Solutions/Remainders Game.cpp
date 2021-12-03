#include<bits/stdc++.h>
using namespace std;
#define maxn 100001

string solve(int n,int k, vector<int> c){
    int spf[maxn],cnt[maxn];
    for(int i=0;i<maxn;i++){
        spf[i]=i;
        cnt[i]=0;
    }
    for(int i=2;i*i<maxn;i++){
        if(spf[i]==i){
            for(int j=i*i;j<maxn;j+=i){
                spf[j]=i;
            }
        }
    }
    for(int i=0;i<n;i++){
        int x=c[i];
        while(x!=1){
            int count=0,p=spf[x];
            while(x%p==0){
                x/=p;
                count++;
            }
            cnt[p]=max(cnt[p],count);
        }
    }
    while(k!=1){
        if(cnt[spf[k]]<=0){
            return "No";
        }
        cnt[spf[k]]--;
        k/=spf[k];
    }
    return "Yes";
}