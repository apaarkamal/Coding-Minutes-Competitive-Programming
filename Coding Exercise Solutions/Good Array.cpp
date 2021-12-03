#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    if(a<b){
        swap(a,b);
    }
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
bool isGoodArray(vector<int> nums) {
    int ans=0;
    for(auto itr:nums)
    {
        ans=gcd(itr,ans);
    }
    return ans==1;
}