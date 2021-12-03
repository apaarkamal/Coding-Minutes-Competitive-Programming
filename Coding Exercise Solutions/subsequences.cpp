#include<bits/stdc++.h>
using namespace std;
#define maxn 100001

long long bit[maxn][12];
void update(long long index,long long x, long long val)
{
	while(index<maxn)
	{
		bit[index][x]+=val;
		index+=index&-index;
	}
}
long long get(long long index,long long x)
{
	long long ans=0;
	while(index>0)
	{
		ans+=bit[index][x];
		index-=index&-index;
	}
	return ans;
}
long long solve(int n, int k, vector<int> seq){
    memset(bit,0,sizeof(bit));
    long long ans=0,val;
    for(int i=0;i<n;i++)
    {
        update(seq[i],1,1);
        for(int j=2;j<=k+1;j++)
        {
            val=get(seq[i]-1,j-1);
            update(seq[i],j,val);
        }
    }
    ans=get(maxn-1,k+1);
    return ans;
    return ans;
}