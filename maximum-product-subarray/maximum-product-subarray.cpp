class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int gmax = nums[0];
        int mx = nums[0];
        int mn = nums[0];
        for(int i=1;i<nums.size();i++)
        {
           if(nums[i]<0) swap(mx,mn); // as -ve will change their value correspoding name
            mx = max(nums[i],nums[i]*mx);
            mn = min(nums[i],nums[i]*mn);
           
           gmax = max(gmax,mx);
        }
        return gmax;
    }
};