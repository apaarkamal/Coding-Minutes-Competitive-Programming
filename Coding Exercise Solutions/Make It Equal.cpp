#include<bits/stdc++.h>
using namespace std;

int solve(int n, int k, vector<int> h){
    int maxi = *max_element(h.begin(), h.end()) + 1;
    vector<int> cnt(maxi, 0);
    for(int i = 0 ; i < n ; i++){
        cnt[0]++;
        cnt[h[i]]--;
    }

    for(int i = 1; i < maxi; i++){
        cnt[i] += cnt[i-1];
    }

    int slices = 0, curr = 0;
    for(int i = maxi-1; i >= 0; i--){
        if(cnt[i] == n) break;
        if(curr + cnt[i] <= k){
            curr += cnt[i];
        }else{
            slices++;
            curr = cnt[i];
        }
    }
    if(curr != 0) slices++;
    return slices;
}
