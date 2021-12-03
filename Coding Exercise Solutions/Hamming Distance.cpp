#include<bits/stdc++.h>
using namespace std;

int hammingDistance(int x, int y) {
    int val=x^y,ans=0;
    while(val)
    {
        val=val&(val-1);
        ans++;
    }
    return ans;
}