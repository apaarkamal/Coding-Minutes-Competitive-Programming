#include<bits/stdc++.h>
using namespace std;

int distributeCandies(vector<int> candies) {
    unordered_set<int>s;
    for(auto itr:candies)
    {
        s.insert(itr);
    }
    int ans=min(s.size(),candies.size()/2);
    return ans;
}