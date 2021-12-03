#include<bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> nums){
    vector<int>mod(n);
    mod[0]++;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=nums[i];
        mod[sum%n]++;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        int x=mod[i];
        ans+=(x*(x-1))/2;
    }
    return ans;
}