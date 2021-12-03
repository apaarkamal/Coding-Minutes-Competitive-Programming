#include<bits/stdc++.h>
using namespace std;

bool BFS(int n, unordered_map<int, set<int>> g) {
    queue<int> q;
    q.push(0);
    unordered_map<int, bool> vis;
    vis[0] = true;
    while (!q.empty()) {
        int P = q.front();
        q.pop();
        for (auto &c : g[P]) {
            if (!vis[c]) {
                vis[c] = true;
                q.push(c);
            }
        }
    }
    return vis.size() == n;
}
bool solve(int n, vector<vector<int>> roads) {
    unordered_map<int, set<int>> g;
    for (auto &c : roads){ 
        g[c[0]].insert(c[1]);
    }

    bool allvis = BFS(n, g);
    if (!allvis){
        return allvis;
    }
    unordered_map<int, set<int>> revg;
    for (auto &[k, v] : g) {
        for (auto &c : v) revg[c].insert(k);
    }
    allvis = BFS(n, revg);
    return allvis;
}