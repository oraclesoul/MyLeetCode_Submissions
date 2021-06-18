/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    TreeNode* ans = NULL;
    bool FIND(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(!root) return false;
        bool lft = FIND(root->left,p,q);
        bool rht =  FIND(root->right,p,q);
        bool slf = (root==p)||(root==q);
        int cnt = 0;
        if(lft) cnt++;
        if(rht) cnt++;
        if(slf) cnt++;
        if(cnt>1)
        {
            ans = root;
            return true;
        }
        if(cnt>0) return true;
        return false;
       
        
        
    }
        
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        FIND(root,p,q);
        return ans;
        
        
    }
};