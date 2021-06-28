class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int l = 0, r = 0;
        while(r<n)
        {
          if(nums[r]!=val)
          {
            nums[l] = nums[r];
            l++;
          }
          r++;
        }
        
        return l;
      
    }
};