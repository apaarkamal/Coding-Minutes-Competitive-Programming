#include<bits/stdc++.h>
using namespace std;
#define INF 1000000009

vector<int>A,val,comp;
vector <vector<int>> v,rev_v,scc_v;
vector<bool>vis;
int components;
vector<set <int>> ss;

/**
 * Push the vertices in the stack in the decreasing order 
 * of their finishing times.
 * 
 * First DFS of the Kosaraju Algorithm
 **/
void dfs_0(int curr,stack<int>&s)
{
    vis[curr] = true;
    for ( int i = 0; i < (int)v[curr].size(); i++ ) {
        if ( vis[v[curr][i]] ) continue;
        dfs_0(v[curr][i],s);
    }
    s.push(curr);    
}

void dfs_1(int curr)
{
    vis[curr] = true;
    comp[curr] = components;
    val[components] = __gcd(val[components], A[curr]);
    for ( int i = 0; i < (int)rev_v[curr].size(); i++ ) {
        if ( vis[rev_v[curr][i]] ) continue; 
        dfs_1(rev_v[curr][i]);
    }
}

void dfs_2(int curr,stack<int>&s)
{
    vis[curr] = true;
    for ( int i = 0; i < (int)scc_v[curr].size(); i++ ) {
        if ( vis[scc_v[curr][i]] ) continue;
        dfs_2(scc_v[curr][i],s);
    }
    s.push(curr);
}

int solve(int n,vector<int> c, vector<vector<int>> edges){
    v=rev_v=scc_v=vector<vector<int>>(n+1,vector<int>());
    A=val=comp=vector<int>(n+1);
    ss=vector<set<int>>(n+1,set<int>());
    stack<int>s;
    vis.assign(n+1,false);
    components=0;
    int  x, y;
    for ( int i = 1; i <= n; i++ ) {
        A[i]=c[i-1];
    }

    for ( int i = 0; i < edges.size(); i++ ) {
        x=edges[i][0],y=edges[i][1];
        v[x].push_back(y);
        rev_v[y].push_back(x);
    }
    
    for ( int i = 1; i <= n; i++ ) {
        if ( !vis[i] ) dfs_0(i,s);
    }
    
    vis.assign(n+1,false);
    
    components = 0;
    
    while ( !s.empty() ) {
        int curr = s.top();
        s.pop();
        if ( !vis[curr] ) {
            components++;
            dfs_1(curr);
        }
    }
    
    //Create an scc condensed dag graph
    //Number of vertices = components
    //Edges -> scc[]
    //Value on each node of this scc - val[i]
    for ( int i = 0; i < edges.size(); i++ ) {
        if ( comp[edges[i][0]] != comp[edges[i][1]] ) {
            scc_v[comp[edges[i][0]]].push_back(comp[edges[i][1]]);
        }        
    }
    
    vis.assign(n+1,false);
    //Perform a topological sort on this.
    
    for ( int i = 1; i <= components; i++ ) {
        if ( !vis[i] ) dfs_2(i,s);
    }
    
    int ans = INF;
    
    while ( !s.empty() ) {
        int curr = s.top();
        s.pop();
        ss[curr].insert(val[curr]);
        ans = min(ans, val[curr]);
        for ( set <int> :: iterator it = ss[curr].begin(); it != ss[curr].end(); it++ ) {
            for ( int j = 0; j < (int)scc_v[curr].size(); j++ ) {
                ss[scc_v[curr][j]].insert(__gcd(*it, val[scc_v[curr][j]]));
                ans = min(ans, __gcd(*it, val[scc_v[curr][j]]));
            }
        }
    }
    return ans;
}