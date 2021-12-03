#include<bits/stdc++.h>
using namespace std;
    
vector<int> closestDivisors(int num) {
    vector<int>arr1,arr2;
    for(int i=sqrt(num+1);i>=1;i--)
    {
        if((num+1)%i==0)
        {
            arr1={i,(num+1)/i};
            break;
        }
    }
    for(int i=sqrt(num+2);i>=1;i--)
    {
        if((num+2)%i==0)
        {
            arr2={i,(num+2)/i};
            break;
        }
    }
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());
    return (arr1[1]-arr1[0])< (arr2[1]-arr2[0])? arr1:arr2;
}