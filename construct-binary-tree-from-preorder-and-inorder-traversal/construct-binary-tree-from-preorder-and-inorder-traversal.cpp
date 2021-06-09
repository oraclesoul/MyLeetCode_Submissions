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
	int prePos = -1;
	TreeNode* createTree(vector<int>& preorder,unordered_map<int,int>&mp,int low,int high)
	{
		if(low>high) return NULL;
        prePos++;
		TreeNode* dummyNode = new TreeNode(preorder[prePos]);
		int inPos = mp[preorder[prePos]];
       
		dummyNode->left =  createTree(preorder,mp,low,inPos-1);
		dummyNode->right = createTree(preorder,mp,inPos+1,high);
		return dummyNode;

	}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++)
        {	
        	mp[inorder[i]]=i;
        }
        
        return createTree(preorder,mp,0,inorder.size()-1);
    }
};