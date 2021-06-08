class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum = 0;
        int j=0,k=n-1;
        for(int i=0;i<n;i++)
        {
            if(j==k)
            {
                sum += mat[i][j];
            }else
            {
                sum += mat[i][j]+mat[i][k];
            }
            j++;
            k--;
        }
        return sum;
    }
};