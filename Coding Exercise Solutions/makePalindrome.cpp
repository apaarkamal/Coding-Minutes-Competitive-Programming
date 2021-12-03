#include<bits/stdc++.h>
using namespace std;
#define maxn 200001
vector<int>par,sz;

int find(int x){
    if(par[x]!=x){
        return par[x]=find(par[x]);
    }
    return x;
}
void Unions(int x,int y){
    int val=find(x),val1=find(y);
    if(val==val1){
        return ;
    }
    if(sz[val]>sz[val1]){
        swap(val,val1);
    }
    par[val]=val1;
    sz[val1]+=sz[val];
}

int solve(int n,vector<int> a){
    par=sz=vector<int>(maxn);
    iota(par.begin(),par.end(),0);
    set<int>s;
    sz.assign(maxn,1);
    for(int i=0;i<n;i++){
        s.insert(a[i]);
    }
    for(int i=0;i<n/2;i++){
        int x=a[i],y=a[n-i-1];
        Unions(x,y);
    }
    int ans=0;
    for(auto itr:s){
        if(find(itr)==itr){
            ans+=sz[itr]-1;
        }
    }
    return ans;
}
