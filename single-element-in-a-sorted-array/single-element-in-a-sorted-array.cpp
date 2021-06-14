class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        
        // before single element  element pos even , odd
        // after single element
        // element pos odd , even
        
        while(low<high)
        {
            int mid = low + (high-low)/2;
            
            if(mid%2)
            {
                if(nums[mid]==nums[mid-1])
                {
                    low = mid+1;
                }else
                {
                    high = mid;
                }
            }else
            {
                if(nums[mid] == nums[mid+1])
                {
                    low = mid+2;
                }else
                {
                    high = mid;
                }
            }
        }
        
        return nums[low];
        
        
    }
};