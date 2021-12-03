#include<bits/stdc++.h>
using namespace std;

int totalHammingDistance(vector<int> nums) {
    int ans=0,n=nums.size();
    for(int i=0;i<=30;i++)
    {
        int ones=0,zeros=0,val=1<<i;
        for(int j=0;j<n;j++)
        {
            if(nums[j]&val)
            {
                ones++;
            }
            else{
                zeros++;
            }
        }
        ans+=ones*zeros;
    }
    return ans;
}