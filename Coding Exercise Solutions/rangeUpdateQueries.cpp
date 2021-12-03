#include<bits/stdc++.h>
using namespace std;
#define maxn 100001

int bit[maxn];
void update(int index,int val)
{
	while(index<maxn)
	{
		bit[index]+=val;
		index+=index&-index;
	}
}
int get(int index)
{
	int ans=0;
	while(index>0)
	{
		ans+=bit[index];
		index-=index&-index;
	}
	return ans;
}
vector<int> solve(int n, vector<int> nums, vector<vector<int>> queries){
    memset(bit,0,sizeof(bit));
    vector<int>ans;
    for(int i=0;i<queries.size();i++)
    {
        int type=queries[i][0];
        if(type==1)
        {
            int a=queries[i][1],b=queries[i][2],u=queries[i][3];
            update(b+1,-u);
            update(a,u);
        }
        else
        {
            int k=queries[i][1];
            ans.push_back(get(k)+nums[k-1]);
        }
    }
    return ans;
}