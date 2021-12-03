#include<bits/stdc++.h>
using namespace std;

int networkDelayTime(vector<vector<int>> times, int N, int K) {
    // build graph 
    vector<vector<pair<int, int> > > graph(N+1);
    for (auto edge : times) {
        int fr_node = edge[0];
        int to_node = edge[1];
        int cost = edge[2];
        graph[fr_node].push_back(make_pair(cost, to_node));            
    }
    vector<int> dist(N+1, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[K] = 0;
    pq.push(make_pair(0, K));        
    while (!pq.empty()) {
        pair<int,int> x = pq.top();
        pq.pop();
        for (auto neighbor : graph[x.second]) {
            int ar = dist[x.second] + neighbor.first;
            if (ar < dist[neighbor.second]) {
                dist[neighbor.second] = ar;
                pq.push(make_pair(ar, neighbor.second));
            }
        }            
    }        
    int max_time = INT_MIN;
    for (int i = 1; i < dist.size(); ++i) {
        if (max_time < dist[i]) {
            max_time = dist[i];
        }
    }
    
    return max_time == INT_MAX? -1 : max_time;
}