#include<bits/stdc++.h>
using namespace std;

long long power9(long long a, long long n){
    long long p;
    if(n==0){
        return 1;
    }
    p=power9(a,n/2);
    p=(p*p)%9;
    if(n%2){
        p=(p*a)%9;
    }
    return p;
}
int solve(long long A, long long N){
    int ans= power9(A, N);
    if(!ans){
        ans=9;
    }
    return ans;
}