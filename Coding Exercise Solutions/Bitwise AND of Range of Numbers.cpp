#include<bits/stdc++.h>
using namespace std;

int rangeBitwiseAnd(int m, int n) {
    int diff=n-m,ans=0;
    for(int i=0;i<31;i++)
    {
        int val=1<<i;
        if(diff/val==0)
        {
            if(n&val && m&val)
            {
                ans+=val;
            }
        }
    }
    return ans;
}