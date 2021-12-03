#include<bits/stdc++.h>
using namespace std;
#define maxn 100001

long long p=29, mod=1e9+7,power[maxn];
int findPattern(string word, string pattern){
    power[0]=1;
    for(int i=1;i<maxn;i++)
    {
        power[i]=(power[i-1] *p)%mod;
    }
    int n=word.size(),m=pattern.size();
    vector<long long>hash(n+1);
    for(int i=0;i<n;i++)
    {
        hash[i+1]= (hash[i] + ((word[i]-'a')*power[i])%mod)%mod;
    }
    long long hash_val=0;
    int ans=0;
    for(int i=0;i<m;i++)
    {
        hash_val = (hash_val + ((pattern[i]- 'a' )*power[i])%mod)%mod;
    }

    for(int i=m;i<=n;i++)
    {
        long long val = ( hash[i]-  hash[i-m] + mod)%mod;
        int new_hash= (hash_val * power[i-m] )%mod;
        if(val==new_hash)
        {
            ans++;
        }
    }
    return ans;
}