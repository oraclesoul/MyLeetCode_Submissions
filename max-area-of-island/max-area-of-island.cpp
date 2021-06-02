class Solution {
public:

    bool vis[50][50];

    int findArea(vector<vector<int>>& grid , int n , int m , int i , int j )
    {
        vis[i][j] = true;
        int a,b,c,d;
        a=b=c=d=0; // for all 4 direction

        if(i+1<n && grid[i+1][j]==1 && !vis[i+1][j]) a = findArea(grid,n,m,i+1,j);
        if(i-1>=0 && grid[i-1][j]==1 && !vis[i-1][j]) b = findArea(grid,n,m,i-1,j);
        if(j+1<m && grid[i][j+1]==1 && !vis[i][j+1]) c = findArea(grid,n,m,i,j+1);
        if(j-1>=0 && grid[i][j-1]==1 && !vis[i][j-1]) d = findArea(grid,n,m,i,j-1);

        return 1+a+b+c+d;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        memset(vis,false,sizeof(vis));
        int n = grid.size();
        int m = grid[0].size();
        int mxarea = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && !vis[i][j]) mxarea = max(mxarea,findArea(grid,n,m,i,j));
            }
        }
        return mxarea;
    }
};