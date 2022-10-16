#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

vector<int> findClosestElements(vector<int> arr, int k, int x) {
    vector <int> K_closest_nums(k);
    
    priority_queue < pii, vector<pii>, greater<pii> > MinHeap;
    
    for(int i = 0; i < arr.size(); ++i)
        MinHeap.push( {abs(arr[i]-x), arr[i]} );
    
    for(int i = 0; i < k; ++i){
        K_closest_nums[i] = MinHeap.top().second;
        MinHeap.pop();
    }
    
    sort(K_closest_nums.begin(),K_closest_nums.end());
    
    return K_closest_nums;
}
