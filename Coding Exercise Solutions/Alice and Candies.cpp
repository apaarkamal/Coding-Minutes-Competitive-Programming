#include<bits/stdc++.h>
using namespace std;

int solve(int n)
{
    int ans=0;
    for(int i=1;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            int x=i,y=n/i;
            if((x+y)%2==0)
            {
                ans++;
            }
        }
    }
    return ans;
}