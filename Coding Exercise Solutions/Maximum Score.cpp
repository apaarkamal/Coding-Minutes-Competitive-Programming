#include<bits/stdc++.h>
using namespace std;

int matrixScore(vector<vector<int>> grid) {
    int ans=0,n=grid.size(),m=grid[0].size();
    ans=(1<<(m-1))*n;
    for(int j=1;j<m;j++)
    {
        int val=1<<(m-1-j);
        int sets=0;
        for(int i=0;i<n;i++)
        {
            if(grid[i][j]==grid[i][0])
            {
                sets++;
            }
        }
        ans+=max(sets,n-sets)*val;
    }
    return ans;
}