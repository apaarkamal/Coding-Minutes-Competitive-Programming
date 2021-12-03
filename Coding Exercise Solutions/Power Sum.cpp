#include<bits/stdc++.h>
using namespace std;

int power(int a,int n){
    if(n==0){
        return 1;
    }
    return a*power(a,n-1);
}

int cal(int x,int n, vector<int>&vec){
    int sum=0,answer=0;
    for(auto itr:vec){
        sum+=power(itr,n);
    }
    if(sum==x){
        return 1;
    }
    else{
        int answer=0;
        int v=vec.empty()?1:vec.back()+1;
        while(sum+ power(v,n)<=x){
            vec.push_back(v);
            answer+=cal(x,n,vec);
            vec.pop_back();
            v++;
        }
        return answer;
    }
}

int solve(int x,int n){
    vector<int>vec;
    return cal(x,n,vec);
}

