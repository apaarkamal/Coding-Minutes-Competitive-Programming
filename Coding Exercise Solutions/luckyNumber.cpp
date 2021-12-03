#include<bits/stdc++.h>
using namespace std;

string solve(int n,int a,int b, vector<int> A)
{
    int cnt1=0,cnt2=0,cnt3=0;
    for(int i=0;i<n;i++)
    {
        if(A[i]%a==0 && A[i]%b==0)
        {
            cnt1++;
        }
        else
        if(A[i]%a==0){
            cnt2++;
        }
        else
        if(A[i]%b==0){
            cnt3++;
        }
    }
    if(cnt1)
    {
        cnt2++;
    }
    if(cnt2>cnt3)
    {
        return "Bob";
    }
    else{
        return "Alice";
    }
}