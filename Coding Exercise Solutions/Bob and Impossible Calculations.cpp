#include<bits/stdc++.h>
using namespace std;

int solve(int n,int m, vector<int> arr){
    long long ans = 1;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            ans*=abs(arr[i]-arr[j]);
            ans%=m;
        }
       
    }
    return ans;
}
