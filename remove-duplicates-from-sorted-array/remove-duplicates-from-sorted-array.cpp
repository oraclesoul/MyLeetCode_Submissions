class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int l = 0 , r = 1;
        if(n==0) return 0;
        while(r<n)
        {
            if(nums[l]!=nums[r])
            {
                nums[l+1]=nums[r];
                l++;
            }
            r++;
        }
        return l+1;
    }
};