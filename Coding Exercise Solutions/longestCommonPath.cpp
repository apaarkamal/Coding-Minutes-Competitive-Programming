#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second

long long mod1=1e9+7,mod2=1e9+9,p1=29,p2=31;
long long power(long long a,long long n,long long mod)
{
    long long p;
    if(n==0)
    {
        return 1;
    }
    p=power(a,n/2,mod);
    p=(p*p)%mod;
    if(n%2)
    {
        p=(p*a)%mod;
    }
    return p;
}
int longestCommonSubpath(int n, vector<vector<int>> paths) {
    long long mini=mod1;
    for(auto itr:paths)
    {
        mini=min(mini,(long long)itr.size());
    }
    long long mi1=power(p1,mod1-2,mod1),mi2=power(p2,mod2-2,mod2);
    long long l=0,r=mini,mid,ans;
    while(l<=r)
    {
        mid=(l+r)/2;
        map<pair<long long,long long>,long long>m;
        for(auto itr:paths)
        {
            set<pair<long long,long long>>s;
            long long x=p1,y=p2,val=0,val1=0;                
            for(int i=0;i<mid;i++)
            {
                val=(val+ (itr[i]*x)%mod1)%mod1;
                val1=(val1+ (itr[i]*y)%mod2)%mod2;
                x=(x*p1)%mod1;
                y=(y*p2)%mod2;
            }
            s.insert({val,val1});
            for(int i=mid;i<itr.size();i++)
            {
                val=(val + (itr[i]*x))%mod1;
                val=(val *mi1)%mod1;
                val=(val- itr[i-mid] +mod1)%mod1;
                val1=(val1 + (itr[i]*y))%mod2;
                val1=(val1 *mi2)%mod2;
                val1=(val1- itr[i-mid] +mod2)%mod2;
                s.insert({val,val1});
            }
            for(auto itr:s)
            {
                m[itr]++;
            }
        }
        int flag=0;
        for(auto itr:m)
        {
            if(itr.se==paths.size())
            {
                flag=1;
                break;
            }
        }
        if(flag)
        {
            ans=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    return ans;
}