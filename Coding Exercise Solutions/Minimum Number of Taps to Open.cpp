#include<bits/stdc++.h>
using namespace std;

int minTaps(int n, vector<int> ranges) {
    vector<pair<int,int>>v;
    for(int i=0;i<=n;i++)
    {
        v.push_back({i-ranges[i],i+ranges[i]});
    }
    sort(v.begin(),v.end());
    int s=0,e=0,ind=0;
    int ans=0;
    while(s<n){
        while(ind<v.size() && v[ind].first<=s){
            e=max(e,v[ind].second);
            ind++;
        }
        if(s==e){
            return -1;
        }
        s=e;
        ans++;
    }
    return ans;
}