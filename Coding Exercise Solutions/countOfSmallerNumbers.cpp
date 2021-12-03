#include<bits/stdc++.h>
using namespace std;

void update(int x,int n,vector<int>&bit)
{
    while(x<n)
    {
        bit[x]+=1;
        x+=x&-x;
    }
}
int get(int x,vector<int>&bit)
{
    int ans=0;
    while(x>0)
    {
        ans+=bit[x];
        x-=x&-x;
    }
    return ans;
}
vector<int> countSmaller(vector<int> nums) {
    int n=nums.size();
    vector<int>bit(n+1);
    vector<int>temp=nums;
    sort(temp.begin(),temp.end());
    for(int i=0;i<n;i++)
    {
        int val=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
        nums[i]=val+1;
    }
    vector<int>ans(n);
    for(int i=n-1;i>=0;i--)
    {
        int val=get(nums[i]-1,bit);
        ans[i]=val;
        update(nums[i],n+1,bit);
    }
    return ans;
}