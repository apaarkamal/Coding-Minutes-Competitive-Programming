#include<bits/stdc++.h>
using namespace std;

vector<long long> subset(vector<int> &v){
    vector<long long>result;
    int n=v.size();
    for(int i=0;i<pow(2,n);i++){
        long long sum=0;
        for(int j=0;j<n;j++){
            int x=1<<j;
            if(x&i){
                sum+=v[j];
            }
        }
        result.push_back(sum);
    }
    return result;
}

long long solve(int n,int x,vector<int> arr){
    vector<int>left,right;
    for(int i=0;i<n;i++){
        if(i<n/2){
            left.push_back(arr[i]);
        }
        else{
            right.push_back(arr[i]);
        }
    }
    vector<long long>left_sum=subset(left);
    vector<long long>right_sum=subset(right);
    
    sort(right_sum.begin(),right_sum.end());
    long long ans=0;
    
    for(int i=0;i<left_sum.size();i++){
        int l=lower_bound(right_sum.begin(),right_sum.end(),x-left_sum[i])-right_sum.begin();
        int r=upper_bound(right_sum.begin(),right_sum.end(),x-left_sum[i])-right_sum.begin();
        ans+=(r-l);
    }
    return ans;
}
