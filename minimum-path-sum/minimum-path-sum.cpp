class Solution {
public:
    int dp[200][200];
    
    int minSum(vector<vector<int>>& grid,int i,int j)
    {
       if(i<0 || j<0) return 1000;
       if(i==0 && j==0) return grid[i][j];
       int &ans = dp[i][j];
       if(ans>-1) return ans;
       ans = grid[i][j] + min(minSum(grid,i-1,j),minSum(grid,i,j-1));
       return ans;
    }

    int minPathSum(vector<vector<int>>& grid) {
       int n = grid.size();
       int m = grid[0].size();
        memset(dp,-1,sizeof(dp));
       int ans = minSum(grid,n-1,m-1);
       return ans;
    }
};