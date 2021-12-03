#include<bits/stdc++.h>
using namespace std;

string getHint(string secret, string guess) {
    int n=secret.size();
    int bull=0,cows=0;
    map<char,int>cnt1,cnt2;
    for(int i=0;i<n;i++)
    {
        if(secret[i]==guess[i])
        {
            bull++;
        }
        else{
            cnt1[secret[i]]++;
            cnt2[guess[i]]++;
        }
    }
    for(auto itr:cnt1){
        int x=cnt2[itr.first],y=itr.second;
        cows+=min(x,y);
    }
    string ans;
    ans+=to_string(bull);
    ans+="A";
    ans+=to_string(cows);
    ans+="B";
    return ans;
}