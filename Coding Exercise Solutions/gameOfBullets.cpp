#include<bits/stdc++.h>
using namespace std;

string solve(int n, vector<int> A)
{
    int val=0;
    for(int i=0;i<n;i++)
    {
        val^=A[i];
    }
    if(val==0)
    {
        return "Isa";
    }
    else{
        return "Gaitonde";
    }
}