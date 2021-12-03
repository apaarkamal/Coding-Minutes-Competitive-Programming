#include<bits/stdc++.h>
using namespace std;

int minEatingSpeed(vector<int> piles, int h) {
    int n=piles.size();
    int l=1,r=*max_element(piles.begin(),piles.end()),mid,ans;
    while(l<=r){
        mid=(l+r)/2;
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt+=(piles[i]+mid-1)/mid;
        }
        if(cnt<=h){
            r=mid-1;
            ans=mid;
        }
        else{
            l=mid+1;
        }
    }
    return ans;
}