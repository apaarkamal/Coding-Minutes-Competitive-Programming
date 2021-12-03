#include<bits/stdc++.h>
using namespace std;

bool comp(const vector<int>&a, const vector<int>&b){
    return a[1]<b[1];
}

long long solve(int n,int m,vector<vector<int>> operation){
    sort(operation.begin(),operation.end(),comp);
    vector<int>component(m+1);
    component[0]=n;
    int val=0;
    for(int i=0;i<m;i++){
        val=__gcd(component[i],operation[i][0]);
        component[i+1]=val;
    }
    if(component[m]!=1){
        return -1;
    }
    long long ans=0;
    for(int i=1;i<=m;i++){
        ans+=(long long)(component[i-1]-component[i])*(long long)operation[i-1][1];
    }
    return ans;
}