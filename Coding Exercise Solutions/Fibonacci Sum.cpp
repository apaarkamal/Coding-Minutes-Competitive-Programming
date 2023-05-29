#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

void multiply(vector<vector<long long>>& F, vector<vector<long long>>&M)
{
    long long x,y,z,w;
    x =  (F[0][0]*M[0][0] + F[0][1]*M[1][0])%mod;
    y =  (F[0][0]*M[0][1] + F[0][1]*M[1][1])%mod;
    z =  (F[1][0]*M[0][0] + F[1][1]*M[1][0])%mod;
    w =  (F[1][0]*M[0][1] + F[1][1]*M[1][1])%mod;

    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

void power(vector<vector<long long>>&F, int n){
    if( n == 0 || n == 1)
      return;

    vector<vector<long long>>M = {{1,1},{1,0}};

    power(F, n/2);
    multiply(F, F);

    if (n%2 != 0){
        multiply(F, M);
    }
}

long long fib(long long n)
{
    vector<vector<long long>> F= {{1,1},{1,0}};
    if (n == 0){
        return 0;
    }
    power(F, n-1);
    return F[0][0];
}

int fibSum(int n,int m){
    int ans=(fib(m+2)-fib(n+1))%mod;
    if(ans<0){
        ans+=mod;
    }
    return ans;
}

