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
    int sum = 0;
    void findNode(TreeNode * root,int gVal)
    {
        if(!root) return;
        if(gVal%2==0)
        {
            if(root->left) sum+=(root->left)->val;
            if(root->right) sum+=(root->right)->val;
            
        }
        
        findNode(root->left,root->val);
        findNode(root->right,root->val);
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        findNode(root,1);
        return sum;
    }
};