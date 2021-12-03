#include<bits/stdc++.h>
using namespace std;

#define inf 1e9

int minSumOfLengths(vector<int> arr, int target) {
    int n=arr.size();
    vector<int>dp(n,inf);
    int ans=inf,len=inf;
    int l=0,r=0,sum=0;
    while(r<n){
        sum+=arr[r];
        
        while(sum>target){
            sum-=arr[l];
            l++;
        }
        if(sum==target){
            if(l!=0 && dp[l-1]!=inf){
                ans=min(ans,dp[l-1]+r-l+1);
            }
            len=min(len, r-l+1);
        }
        dp[r]=len;
        r++;
    }
    return ans==inf?-1:ans;
}