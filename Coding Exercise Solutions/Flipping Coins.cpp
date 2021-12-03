#include<bits/stdc++.h>
using namespace std;
vector<int>seg,lazy;

void update(int v,int l,int r,int x,int y){
   
    if(lazy[v]){
        seg[v]=(r-l+1)-seg[v];
        if(l!=r){
            lazy[2*v]^=1;
            lazy[2*v+1]^=1;
        }
        lazy[v]=0;
    }
    if(y<x){
        return;
    }
    if(x<=l && y>=r){
        seg[v]=(r-l+1)-seg[v];
        if(l!=r){
            lazy[2*v]^=1;
            lazy[2*v+1]^=1;
        }
        return;
    }
    int mid=(l+r)/2;
    update(2*v,l,mid,x,min(mid,y));
    update(2*v+1,mid+1,r,max(x,mid+1),y);
    seg[v]=seg[2*v]+seg[2*v+1];
}

int range(int v,int l,int r,int x,int y){
    if(y<x){
        return 0;
    }
    if(lazy[v]){
        seg[v]=(r-l+1)-seg[v];
        if(l!=r){
            lazy[2*v]^=lazy[v];
            lazy[2*v+1]^=lazy[v];
        }
        lazy[v]^=1;
    }
    if(x<=l && y>=r){
        return seg[v];
    }
    int mid=(l+r)/2;
    return range(2*v,l,mid,x,min(y,mid))+range(2*v+1,mid+1,r,max(mid+1,x),y);
}

vector<int> solve(int n,int q, vector<vector<int>> query){
    seg=lazy=vector<int>(4*n+1);
    vector<int>ans;
    for(int i=0;i<q;i++){
        int type=query[i][0],x=query[i][1],y=query[i][2];
        if(type==0){
            update(1,0,n-1,x,y);
        }
        else{
            ans.push_back(range(1,0,n-1,x,y));
        }
    }
    return ans;
}
