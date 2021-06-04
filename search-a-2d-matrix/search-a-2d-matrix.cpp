class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();

        for(int i=0;i<n;i++)
        {
            if(target>=matrix[i][0] && target<=matrix[i].back())
            {
                return binary_search(matrix[i].begin(),matrix[i].end(),target);
            }
        }

        return false;      
    }
};