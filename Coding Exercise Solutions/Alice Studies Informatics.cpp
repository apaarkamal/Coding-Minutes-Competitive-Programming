#include<bits/stdc++.h>
using namespace std;

int solve(int l,int r,int x,int y){
    if(y%x!=0)
    {
        return 0;
    }
    int ans=0;
    l=(l+x-1)/x;
    r/=x;
    y/=x;
    for(int i=1;i<=sqrt(y);i++)
    {
        if(y%i==0)
        {
            int val1=i,val2=y/i;
            int gcd=__gcd(val1,val2);
            if(gcd==1 && (val1>=l && val1<=r) && (val2>=l && val2<=r)){
                ans++;
                if(val1!=val2){
                    ans++;
                }
            } 
        }
    }
    return ans;
}