#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1e18

int maxProduct(vector<int> nums) {
    ll n=nums.size();
    ll ans=nums[0],cur_max=nums[0],cur_min=nums[0];
    for(int i=1;i<n;i++)
    {
        if(nums[i]>=0)
        {
            cur_max=max(cur_max*(ll)nums[i],(ll)nums[i]);
            cur_min=min(cur_min*(ll)nums[i],(ll)nums[i]);
        }
        else{
            ll temp_max=max(cur_min*(ll)nums[i],(ll)nums[i]);
            cur_min=min(cur_max*(ll)nums[i],(ll)nums[i]);
            cur_max=max(temp_max,(ll)nums[i]);
        }
        ans=max(ans,cur_max);
    }
    return ans;
}