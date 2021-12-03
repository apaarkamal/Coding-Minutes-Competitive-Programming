#include<bits/stdc++.h>
using namespace std;

vector<int> decode(vector<int> encoded, int first) {
    int n=encoded.size();
    vector<int>ans(n+1);
    ans[0]=first;
    int pre=ans[0];
    for(int i=1;i<=n;i++)
    {
        ans[i]=pre^encoded[i-1];
        pre=ans[i];
    }
    return ans;
}