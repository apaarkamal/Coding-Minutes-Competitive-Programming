#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
const int inf = 1e9;
class Dijkstra
{
	public:
	vector<int> dis,par;
	vector<vector<pair<int,int>>> adj;
	Dijkstra(int n,vector<vector<pair<int,int>>> A)
	{
		dis.resize(n+1);
		par.resize(n+1,0);
		for(int i=1;i<=n;++i)
			dis[i]=inf;	
		adj = A; 
	}
	
	void find_dis(int root)
	{
		set<pair<int,int>> s;
		s.insert({0,root});
		dis[root]=0;
		par[root]=root;
		while(!s.empty())
		{
			pair<int,int> p=*s.begin();
			s.erase(p);
			for(auto i:adj[p.se])
			{
				if(p.fi+i.fi<dis[i.se])
				{
					s.erase({dis[i.se],i.se});
					dis[i.se]=p.fi+i.fi;
					par[i.se]=p.se;
					s.insert({dis[i.se],i.se});
				}
			}
		}
	}
	
	vector<int> find_path(int root)
	{
		vector<int> path;
		int p=root;
		while(p!=1)
		{
			path.pb(p);
			p=par[p];
		}
		path.pb(1);
		reverse(path.begin(),path.end());
		return path;
	}	
};

vector<int> shortestPath(vector<vector<int>> roads,int n)
{
    vector<vector<pair<int,int>>> adj(n+1);
    for(auto i : roads)
    {
        adj[i[0]].pb({i[2],i[1]});
        adj[i[1]].pb({i[2],i[0]});
    }
    
    Dijkstra d(n,adj);
	d.find_dis(1);

	
	return  d.find_path(n);;
}