#include<bits/stdc++.h>
using namespace std;

vector<int> solve(int n,int m,vector<int>a, vector<int>b)
{
    vector<int>ans(m);
    int gcd=0;
    for(int i=1;i<n;i++)
    {
        a[i]=abs(a[i]-a[0]);
        gcd=__gcd(gcd,a[i]);
    }
    for(int i=0;i<m;i++)
    {
        ans[i]=__gcd(gcd,a[0]+b[i]);
    }
    return ans;
}