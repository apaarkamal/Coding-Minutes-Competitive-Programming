#include<bits/stdc++.h>
using namespace std;

int node,trie[300001][26],cnt[300001];
map<int, string>vec;
void insert(vector<string>&words)
{
    for(int i=0;i<words.size();i++)
    {
        int val=0,val1;
        for(auto itr:words[i])
        {
            val1=itr-'a';
            if(!trie[val][val1])
            {
                trie[val][val1]=++node;
            }
            val=trie[val][val1];
        }
        cnt[val]++;
        vec.insert({val,words[i]});
    }
}
void find(int x,int y,int n,int m,vector<vector<char>>&board,int pos,vector<string>&ans)
{
    if(cnt[pos]>0)
    {
        ans.push_back(vec[pos]);
        cnt[pos]=0;
    }
    if(x<0 || y<0 || x>=n || y>=m || board[x][y]=='#')
    {
        return;
    }
    int val=board[x][y]-'a';
    if(!trie[pos][val])
    {
        return;
    }
    char ch=board[x][y];
    board[x][y]='#';
    find(x+1,y,n,m,board,trie[pos][val],ans);
    find(x-1,y,n,m,board,trie[pos][val],ans);
    find(x,y+1,n,m,board,trie[pos][val],ans);
    find(x,y-1,n,m,board,trie[pos][val],ans);
    board[x][y]=ch;
}
vector<string> findWords(vector<vector<char>> board, vector<string> words) {
    int n=board.size(),m=board[0].size();
    memset(trie,0,sizeof(trie));
    memset(cnt,0,sizeof(cnt));
    vec.clear();
    node=0;
    vector<string>ans;
    insert(words);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            find(i,j,n,m,board,0,ans);
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}