#include<bits/stdc++.h>
using namespace std;

bool comp(vector<int> &v1, vector<int> &v2){
    if(v1[0]==v2[0]){
        return v1[1]<v2[1];
    }
    return v1[0]<v2[0];
}
bool cw(vector<int>& a, vector<int>& b, vector<int>& c){
    return (a[0]*(c[1]-b[1]) + b[0]*(a[1]-c[1]) + c[0]*(b[1]-a[1]))>0;
}

bool ccw(vector<int>& a, vector<int>& b, vector<int>& c){
    return (a[0]*(c[1]-b[1]) + b[0]*(a[1]-c[1]) + c[0]*(b[1]-a[1]))<0;
}

vector<vector<int>> outerTrees(vector<vector<int>> trees) {
    sort(trees.begin(),trees.end(),comp);
    int n=trees.size();
    
    if(n<3){
        return trees;
    }
    vector<vector<int>>convex_hull,up,down;
    
    vector<int>first=trees[0],last=trees.back();
    
    up.push_back(first);
    down.push_back(first);
    
    for(int i=1;i<n;i++){
        if(i==n-1 || !ccw(first,trees[i],last)){
            while(up.size()>=2 && ccw(up[up.size()-2],up.back(),trees[i])){
                up.pop_back();
            }
            up.push_back(trees[i]);
        }
        if(i==n-1 || !cw(first,trees[i],last)){
            while(down.size()>=2 && cw(down[down.size()-2],down.back(),trees[i])){
                down.pop_back();
            }
            down.push_back(trees[i]);
        }
    }
    for(auto itr:up){
        convex_hull.push_back(itr);
    }
    for(auto itr:down){
        convex_hull.push_back(itr);
    }
    sort(convex_hull.begin(),convex_hull.end());
    
    convex_hull.resize(unique(convex_hull.begin(),convex_hull.end())-convex_hull.begin());
    
    return convex_hull;
}