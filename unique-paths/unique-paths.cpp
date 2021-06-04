class Solution {
public:
    int ar[101][101];
    int uniquePaths(int m, int n) {
        memset(ar,0,sizeof(ar));
        ar[1][1]=1;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                ar[i][j] += ar[i-1][j]+ar[i][j-1];
            }
        }
        return ar[m][n];
    }
};