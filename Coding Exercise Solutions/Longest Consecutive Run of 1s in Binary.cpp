#include<bits/stdc++.h>
using namespace std;

int solve(int n) {
    int ans=0,cnt=0;
    for(int i=0;i<31;i++)
    {
        int val=1<<i;
        if(val&n)
        {
            cnt++;
            ans=max(ans,cnt);
        }
        else{
            cnt=0;
        }
    }
    return ans;
}