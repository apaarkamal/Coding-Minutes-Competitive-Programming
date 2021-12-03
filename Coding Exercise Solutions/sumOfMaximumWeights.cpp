#include<bits/stdc++.h>
using namespace std;

int find(int x,vector<int>&par){
    if(x!=par[x])
    {
        return par[x]=find(par[x],par);
    }
    return x;
}
void Unions(int x,int y,vector<int>&par, vector<int>& sz){
    int val=find(x,par),val1=find(y,par);   
    if(val==val1){
        return;
    }
    if(sz[val]>sz[val1]){
        swap(val,val1);
    }
    sz[val1]+=sz[val];
    par[val]=val1;
}

bool comp(const vector<int>&v1, const vector<int>&v2){
    return v1[2]<v2[2];
}

long long solve(int n,vector<vector<int>> edges){
    vector<int>par(n+1),sz(n+1,1);
    iota(par.begin(),par.end(),0);
    sort(edges.begin(),edges.end(),comp);
    long long ans=0;
    for(int i=0;i<edges.size();i++){
        long long x=edges[i][0],y=edges[i][1],val=edges[i][2];
        ans+=((long long)sz[find(x,par)]*(long long)sz[find(y,par)])*(long long)val;
        Unions(x,y,par,sz);
    }
    return ans;
}