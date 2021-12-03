#include<bits/stdc++.h>
using namespace std;
#define maxn 100001

set<int> factors(int x,vector<int>&spf){
    set<int>ret;
    while(x!=1)
    {
        ret.insert(spf[x]);
        x/=spf[x];
    }
    return ret;
}
int find(int x,vector<int>&par){
    if(x!=par[x])
    {
        return par[x]=find(par[x],par);
    }
    return x;
}
void Unions(int x,int y,vector<int>&par, vector<int>&sz){
    int val=find(x,par),val1=find(y,par);
    if(val==val1)
    {
        return;
    }
    if(sz[val]>sz[val1])
    {
        swap(val,val1);
    }
    par[val]=val1;
    sz[val1]+=sz[val];
}
bool gcdSort(vector<int> nums) {
    vector<int>spf(maxn),par(maxn),sz(maxn);
    int n=nums.size();
    for(int i=0;i<maxn;i++){
        spf[i]=i;
        par[i]=i;
        sz[i]=1;
    }
    for(int i=2;i*i<maxn;i++)
    {
        if(spf[i]==i){
            for(int j=i*i;j<maxn;j+=i)
            {
                spf[j]=i;
            }
        }
    }
    vector<int>temp=nums;
    sort(temp.begin(),temp.end());
    for(int i=0;i<n;i++)
    {
        set<int>s=factors(nums[i],spf);
        for(auto itr:s)
        {
            Unions(nums[i],itr,par,sz);
        }
    }
    for(int i=0;i<n;i++){
        if(nums[i]!=temp[i] && find(nums[i],par)!=find(temp[i],par)){
            return false;
        }
    }
    return true;
}