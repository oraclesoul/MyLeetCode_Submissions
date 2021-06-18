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
    vector<int> rightSideView(TreeNode* root) {
        vector< int > ans;
        if(!root) return ans;
        queue< TreeNode* > q;
        q.push(root);
        
        while(!q.empty())
        {
            int n = q.size();
            ans.push_back(0);
            for(int i=0;i<n;i++)
            {
                TreeNode* tptr = q.front();
                ans.back() = tptr->val;
                q.pop();
                if(tptr->left) q.push(tptr->left);
                if(tptr->right) q.push(tptr->right);
            }
        }
        return ans;
    }
};