#include<bits/stdc++.h>
using namespace std;

bool mycompare(int a,int b){
    return a>b;
}

vector<int> findClosestElements(vector<int> arr, int k, int x) {
    vector<int>ans;
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>q;
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        int diff=abs(arr[i]-x);
        q.push({diff,arr[i]});
    }
    while(k--)
    {
        ans.push_back(q.top().second);
        q.pop();
    }
    sort(ans.begin(),ans.end(),mycompare);
    return ans;
}