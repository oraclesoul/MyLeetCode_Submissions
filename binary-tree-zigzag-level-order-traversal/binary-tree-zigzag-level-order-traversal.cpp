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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector< vector< int > > ans;
        if(!root) return ans;
        deque< TreeNode* > q;
        q.push_back(root);
        
        bool dir = false;
        while(!q.empty())
        {
            int n = q.size();
            ans.push_back({});
            if(dir)
            {
                for(int i =0;i<n;i++)
                {
                    TreeNode* ptr = q.back();
                    q.pop_back();
                    ans.back().push_back(ptr->val);
                    if(ptr->right)
                    q.push_front(ptr->right);
                    if(ptr->left)
                    q.push_front(ptr->left);
                }
            }else
            {
                for(int i=0;i<n;i++)
                {
                    TreeNode* ptr = q.front();
                    q.pop_front();
                    ans.back().push_back(ptr->val);
                    if(ptr->left) q.push_back(ptr->left);
                    if(ptr->right) q.push_back(ptr->right);
                }
            }
            
            dir ^=true;
        }
        return ans;
    }
};