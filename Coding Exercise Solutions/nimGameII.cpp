#include<bits/stdc++.h>
using namespace std;

string solve(int n, vector<int> heaps){
    for(int i=0;i<n;i++)
    {
        heaps[i]%=4;
    }
    int xr=0;
    for(int i=0;i<n;i++)
    {
        xr^=heaps[i];
    }
    if(xr)
    {
        return "first";
    }
    else{
        return "second";
    }
}