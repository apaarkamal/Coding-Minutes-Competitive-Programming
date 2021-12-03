#include<bits/stdc++.h>
using namespace std;
int ans;
void checkCount(vector<int>&nums,int l,int mid,int r){
    int leftend=l,rightend=mid+1,ptr=mid+1,cnt=0,ind=0;
    vector<int>temp(r-l+1);
    while(leftend<=mid){
        while(rightend<=r && nums[leftend]> (long long)2*(long long)nums[rightend]){
            cnt++;
            rightend++;
        }
        ans+=cnt;
        while(ptr<=r && nums[leftend]>=nums[ptr]){
            temp[ind++]=nums[ptr++];
        }
        temp[ind++]=nums[leftend++];
    }
    while(ptr<=r){
        temp[ind++]=nums[ptr++];
    }
    for(int i=0;i<ind;i++){
        nums[l++]=temp[i];
    }
}

void mergeSort(vector<int>&nums,int l,int r){
    if(l<r){
        int mid=(l+r)/2;
        mergeSort(nums,l,mid);
        mergeSort(nums,mid+1,r);
    
        checkCount(nums,l,mid,r);
    }
}

int reversePairs(vector<int> nums) {
    int n=nums.size();
    if(n==0){
        return 0;
    }
    ans=0;
    mergeSort(nums,0,n-1);
    return ans;
}
