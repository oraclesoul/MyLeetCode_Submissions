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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector< vector< int > > ans;
        if(!root) return ans;
        
        unordered_map< TreeNode* , bool > mp;
        queue< TreeNode* > q;
        mp[root] = true;
        q.push(root);
        
        while(!q.empty())
        {
            int n = q.size();
            ans.push_back({});
            for(int i=0;i<n;i++)
            {
                TreeNode * ptr = q.front();
                ans.back().push_back(ptr->val);
                q.pop();
                if(ptr->left && !mp[ptr->left]) 
                {
                    q.push(ptr->left);
                    mp[ptr->left] = true;
                }
                if(ptr->right && !mp[ptr->right]) 
                {
                    q.push(ptr->right);
                    mp[ptr->right] = true;
                }
            }
        }
        return ans;
        
        
    }
};