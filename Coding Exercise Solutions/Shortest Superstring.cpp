#include<bits/stdc++.h>
using namespace std;

//Travelling salesman problem 
//cost moving from one string to another is nonoverlapping string between them
int n;
string solve(int pos,int val,vector<vector<string>>&dp,vector<vector<string>>&v)
{
    if(val==0)
    {
        return "";
    }
    if(dp[pos][val].size()!=0)
    {
        return dp[pos][val];
    }
    string ans="";
    for(int i=0;i<n;i++)
    {
        int val1=1<<i;
        if(val&val1)
        {
            string str=v[pos][i]+solve(i,val^val1,dp,v);
            if(ans.size())
            {
                ans=ans.size()>str.size()?str:ans;
            }
            else{
                ans=str;
            }
        }
    }
    return dp[pos][val]=ans;
}
string shortestSuperstring(vector<string> words) {
    n=words.size();
    vector<vector<string>>v(n,vector<string>(n,""));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            {
                continue;
            }
            string str=words[j];
            for(int k=0;k<words[i].size();k++)
            {
                string str1,str2;
                str1=words[i].substr(k);
                for(int k1=1;k1<=words[j].size();k1++)
                {
                    str2=words[j].substr(0,k1);
                    if(str1==str2)
                    {
                        str=words[j].substr(k1);
                        goto x;
                    }
                }
            }
            x:;
            v[i][j]=str;
        }
    }
    string ans;
    int val=1<<n;
    val--;
    vector<vector<string>>dp(n,vector<string>(val,""));
    for(int i=0;i<n;i++)
    {
        string str=words[i];
        str+=solve(i,val^(1<<i),dp,v);
        if(ans.size())
        {
            ans=ans.size()>str.size()?str:ans;
        }
        else{
            ans=str;
        }
    }   
    return ans;
}