#include<bits/stdc++.h>
using namespace std;

bool palindrome(string &str){
    string temp=str;
    reverse(temp.begin(),temp.end());
    return temp==str;
}

void solve(string &str, int pos,vector<string>&cur, vector<vector<string>>&ans){
    if(pos>=str.size()){
        ans.push_back(cur);
        return;
    }
    for(int i=pos;i<str.size();i++){
        string temp=str.substr(pos,i-pos+1);
        if(palindrome(temp)){
            cur.push_back(temp);
            solve(str,i+1,cur,ans);
            cur.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>>ans;
    vector<string>cur;
    solve(s,0,cur,ans);
    return ans;
}