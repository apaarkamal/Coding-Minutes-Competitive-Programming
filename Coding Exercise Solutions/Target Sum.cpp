#include<bits/stdc++.h>
using namespace std;

int ans;
void solve(int x,vector<int>&nums,int sum,char ch,int val,int n)
{
    if(x==n-1)
    {
        if(sum+(ch=='+'?nums[x]:-nums[x])==val)
        {
            ans++;
        }
        return;
    }
    solve(x+1,nums,sum+(ch=='+'?nums[x]:-nums[x]),'+',val,n);
    solve(x+1,nums,sum+(ch=='+'?nums[x]:-nums[x]),'-',val,n);
}
int findTargetSumWays(vector<int> nums, int target) {
    ans=0;
    int n=nums.size ();
    solve(0,nums,0,'+',target,n);
    solve(0,nums,0,'-',target,n);
    return ans;
}