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
    
    bool findLCA(TreeNode* root , TreeNode* p , TreeNode* q , TreeNode* &ans)
    {
      if(!root) return false;
      bool lft,rht;
      lft = findLCA(root->left,p,q,ans);
      rht = findLCA(root->right,p,q,ans);
      
      int cnt = 0;
      if(lft) cnt++;
      if(rht) cnt++;
      if(root==p) cnt++;
      if(root==q) cnt++;
      if(cnt>1)
      {
        ans = root;
      }
      if(cnt>0) return true;
      return false;
      
    }
  
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode * ans = NULL;
        findLCA(root,p,q,ans);
        return ans;
    }
};