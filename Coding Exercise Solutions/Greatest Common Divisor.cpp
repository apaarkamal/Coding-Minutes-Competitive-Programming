#include<bits/stdc++.h>
using namespace std;

int solve(int a,int b){
    if(a<b){
        swap(a,b);
    }
    if(b == 0){
           return a;
    }     

    return solve(b,a%b);
}