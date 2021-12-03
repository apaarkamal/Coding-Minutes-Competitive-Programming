#include<bits/stdc++.h>
using namespace std;

string solve(int n, vector<int> balls){
    int xr=0;
    for(int i=0;i<n;i++)
    {
        if(i%2)
        {
            xr^=balls[i];
        }
    }
    if(xr)
    {
        return "first";
    }
    else{
        return "second";
    }
}