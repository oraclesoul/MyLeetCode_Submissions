class Solution {
public:
    
    TreeNode* buildTree(vector<int>&nums,int low,int high)
    {
       if(low>high) return NULL;
       int mxidx = low;
       for(int i=low;i<=high;i++)
       {
          if(nums[mxidx]<nums[i]) mxidx = i;
       }
       TreeNode * node = new TreeNode(nums[mxidx]);
       node->left = buildTree(nums,low,mxidx-1);
       node->right = buildTree(nums,mxidx+1,high);
       return node;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return buildTree(nums,0,nums.size()-1);
    }
};