#include<bits/stdc++.h>
using namespace std;

vector<int> smallestRange(vector<vector<int>> nums) {
    vector<pair<int,int>>vec;
    vector<int>res;
    int k=nums.size();
    for(int i=0;i<k;i++)
    {
        sort(nums[i].begin(),nums[i].end());
        for(auto itr:nums[i])
        {
            vec.push_back({itr,i});
        }
    }
    sort(vec.begin(),vec.end());
    unordered_map<int,int>cnt;
    int l=0,r=0;
    while(r<vec.size())
    {
        cnt[vec[r].second]++;
        while(cnt.size()==k)
        {
            if(res.empty() || vec[r].first-vec[l].first< res[1]-res[0])
            {
                res={vec[l].first,vec[r].first};
            }
            cnt[vec[l].second]--;
            if(cnt[vec[l].second]==0)
            {
                cnt.erase(vec[l].second);
            }
            l++;
        }
        r++;
    }
    return res;
}