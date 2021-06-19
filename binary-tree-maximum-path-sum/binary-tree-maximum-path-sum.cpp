/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = INT_MIN;
    
    int findMaxPath(TreeNode* root)
    {
        if(!root) return -10000;
        int self = root->val;
        int left = findMaxPath(root->left);
        int right = findMaxPath(root->right);
        ans = max({ans,self,left,right,self+left+right});
        return max({self,left+self,right+self});
    }
    
    int maxPathSum(TreeNode* root) {
        int k = findMaxPath(root);
        ans =  max(k,ans);
        return ans;
    }
};