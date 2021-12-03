#include<bits/stdc++.h>
using namespace std;

int maxCoins(vector<int> piles)
{
    sort(piles.begin(),piles.end());
    int ans=0,n=piles.size();
    for(int i=n/3;i<n;i+=2)
    {
        ans+=piles[i];
    }
    return ans;
}