#include<bits/stdc++.h>
using namespace std;

int trie[500001][26],cnt[500001],node;
void insert(string &str)
{
    int val=0,n=str.size();
    for(int i=0;i<n;i++)
    {
        int x=str[i]-'a';
        if(trie[val][x]==0)
        {
            trie[val][x]=++node;
        }
        val=trie[val][x];
    }
    cnt[val]++;
}
bool game(int cur, int turn)
{
    if(cnt[cur])
    {
        return true;
    }
    for(int i=0;i<26;i++)
    {
        int val=trie[cur][i];
        if(val && !game(val, turn^1))
        {
            return true; 
        }
    }
    return false;
}
bool solve( vector<string> words ){
    int n=words.size();
    node=0;
    memset(trie,0,sizeof(trie));
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<n;i++)
    {
        insert(words[i]);
    }
    return game(0, 1);
}