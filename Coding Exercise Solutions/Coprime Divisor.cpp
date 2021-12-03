#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
    if(a<b){
        swap(a,b);
    }
    if(b==0)
    {
        return a;
    }
    return gcd(b,a%b);
}
int solve(int a, int b) {
    while(gcd(a,b)!=1)
    {
        a/=gcd(a,b);
    }
    return a;
}
