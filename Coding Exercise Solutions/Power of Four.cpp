#include<bits/stdc++.h>
using namespace std;

bool isPowerOfFour(int n) {
    if(n<=0)
    {
        return false;
    }
    return (n&(n-1))==0  && (1431655765&n)==n;
}