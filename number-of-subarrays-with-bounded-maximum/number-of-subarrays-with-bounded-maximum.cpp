class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right){
        
        int ans = 0;
        int prevCnt = 0;
        int start = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<=right && nums[i]>=left)
            {
                prevCnt = (i - start + 1);
                ans += prevCnt;
            }else if(nums[i]<left)
            {
                ans += prevCnt;
            }else
            {
                prevCnt = 0;
                start = i+1;
            }
        }
        
        return ans;
        
    }
};