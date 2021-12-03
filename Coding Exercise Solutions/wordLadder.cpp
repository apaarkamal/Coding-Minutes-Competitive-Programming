#include<bits/stdc++.h>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string> wordList) {
    unordered_set<string>s;
    for(auto itr:wordList)
    {
        s.insert(itr);
    }
    queue<string>q;
    int ans=0;
    q.push(beginWord);
    while(!q.empty())
    {
        ans++;
        vector<string>v;
        int n=q.size();
        for(int i=0;i<n;i++)
        {
            string str=q.front();
            if(str==endWord){
                return ans;
            }
            for(int j=0;j<str.size();j++)
            {
                char ch=str[j];
                for(int k=0;k<26;k++)
                {
                    str[j]=char(97+k);
                    if(s.find(str)!=s.end())
                    {
                        v.push_back(str);
                        s.erase(str);
                    }
                }
                str[j]=ch;
            }
            q.pop();
        }
        for(auto itr:v)
        {
            q.push(itr);
        }
    }
    return 0;     
}