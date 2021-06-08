class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>>ans;
        int lasti = INT_MIN;
        for(int i=0;i<n-2;i++)
        {   
            if(nums[i]==lasti) continue;
            lasti = nums[i];
            int plow = INT_MIN;
            int low = i+1;
            int high = n-1;
            int sum = -nums[i];
            while(low<high)
            {
                if(nums[low]+nums[high]==sum)
                {
                    if(nums[low]!=plow)
                    {
                        ans.push_back({nums[i],nums[low],nums[high]});
                        plow = nums[low];
                        low++;
                        high--;
                    }else
                    {
                        low++;
                        high--;
                    }
                }else if(nums[low]+nums[high]<sum)
                {
                    low++;
                }else
                {
                    high--;
                }
            }
        }
        return ans;

        
    }
    
};