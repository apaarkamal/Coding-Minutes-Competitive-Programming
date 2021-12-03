#include<bits/stdc++.h>
using namespace std;

int block,total;
bool comp(const vector<int>&v1, const vector<int>&v2){
    int x=(v1[0]+1)/block,y=(v2[0]+1)/block;
    if(x==y){
        return v1[1]<v2[1];
    }
    return x<y;
}
 
void add(int x,int val,vector<int>&cnt){
    if(x>cnt.size()){
        return;
    }
    if(cnt[x]==x){
        total--;
    }
    cnt[x]+=val;
    if(cnt[x]==x){
        total++;
    }
}
 
vector<int> solve(int n,int m,vector<int> a, vector<vector<int>> query){
    block=n/(int)sqrt(n);
    total=0;
    
    vector<vector<int>>vec(m);
    for(int i=0;i<m;i++){
        vec[i]={query[i][0]-1,query[i][1]-1,i};
    }
    sort(vec.begin(),vec.end(),comp);
 
    vector<int>ans(m),cnt(n+1);
    int curl=0,curr=0;
 
    for(int i=0;i<m;i++){
        int l=vec[i][0],r=vec[i][1];
        while(curl<l){
            add(a[curl],-1,cnt);
            curl++;
        }
        while(curl>l){
            add(a[curl-1],1,cnt);
            curl--;
        }
        while(curr<=r){
            add(a[curr],1,cnt);
            curr++;
        }
        while(curr>r+1){
            add(a[curr-1],-1,cnt);
            curr--;
        }
        ans[vec[i][2]]=total;
    }
    return ans;
}
