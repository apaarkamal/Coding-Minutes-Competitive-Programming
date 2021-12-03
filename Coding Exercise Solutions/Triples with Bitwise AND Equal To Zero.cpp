#include<bits/stdc++.h>
using namespace std;

int countTriplets(vector<int> nums) {
    unordered_map<int,int>store;
    int n=nums.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        {
            int val=nums[i]&nums[j];
            store[val]++;
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(auto itr:store)
        {
            if((itr.first&nums[i])==0)
            {
                ans+=itr.second;
            }
        }
    }
    return ans;
}