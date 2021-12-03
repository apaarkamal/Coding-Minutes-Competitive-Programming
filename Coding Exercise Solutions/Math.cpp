#include<bits/stdc++.h>
using namespace std;

vector<int> solve(int n){
    map<int,int>primes;
    for(int i=2;i<=sqrt(n);i++)
    {
        while(n%i==0)
        {
            n/=i;
            primes[i]++;
        }
    }
    if(n>1)
    {
        primes[n]++;
    }   
    int value=1,x=0;
    for(auto itr: primes){
        x=max(x,(int)ceil(log2(itr.second)));
        value*=itr.first;
    }
    int cnt=0,val=1<<x;
    for(auto itr:primes){
        cnt+=val-itr.second;
    }
    if(cnt){
        x++;
    }
    vector<int>ans={value,x};
    return ans;
}