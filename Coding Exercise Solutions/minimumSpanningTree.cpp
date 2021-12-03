#include<bits/stdc++.h>
using namespace std;

vector<int>visit,sz;
bool comp(const vector<int>& arr1, const vector<int>& arr2)
{
	return arr1[2]<arr2[2];
}
int find(int x,vector<int>&visit)
{
	if(x!=visit[x])
	{
		return visit[x]=find(visit[x],visit);
	}
	return x;
}
void Union(int x,int y,vector<int>&visit, vector<int>&sz)
{
	int val=find(x,visit),val1=find(y,visit);
	if(val==val1)
	{
		return;
	}
	if(sz[val]>sz[val1])
	{
		swap(val,val1);
	}
	visit[val]=val1;
	sz[val1]+=sz[val];
}
int MST(int n, vector<vector<int>> edges)
{
	int x,y,val;
	visit=sz=vector<int>(n+1,1);
	iota(visit.begin(),visit.end(),0);
	sort(edges.begin(),edges.end(),comp);
	int ans=0;
	for(int i=0;i<edges.size();i++)
	{
		x=edges[i][0],y=edges[i][1],val=edges[i][2];
		if(find(x,visit)!=find(y,visit))
		{
			ans+=val;
			Union(x,y,visit,sz);
		}
	}	
	return ans;
}