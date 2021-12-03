#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> nums) {
    priority_queue<int, vector<int>, greater<int>> pq;
    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
        pq.push(nums[i]);
    }
    int a, b, sum;
    while (pq.size() > 1) {
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();
        sum = a + b;
        ans += sum;
        pq.push(sum);
    }
    return ans;
}