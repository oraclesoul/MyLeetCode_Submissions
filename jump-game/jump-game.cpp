class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int mxidx = 0;
        for(int i=0;i<n;i++)
        {
          if(mxidx>=i)
          {
            mxidx = max(mxidx , i + nums[i]);
          }
        }
        
        if(mxidx>=n-1) return true;
        return false;
    }
};