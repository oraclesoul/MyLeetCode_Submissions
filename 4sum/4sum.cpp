class Solution {
public:
    set<vector<int>>s;
    void findPossiblequas(vector<int>& nums, int sum,int low,int high,int i,int j)
    {
        if(low>=high) return;

        if(nums[low]+nums[high]==sum)
        {
            vector<int>v = {nums[i],nums[j],nums[low],nums[high]};
            s.insert(v);
            v.clear();
            findPossiblequas(nums,sum,low+1,high,i,j);
            findPossiblequas(nums,sum,low,high-1,i,j);
        }else if(nums[low]+nums[high]<sum)
        {
            findPossiblequas(nums,sum,low+1,high,i,j);
        }else
        {
            findPossiblequas(nums,sum,low,high-1,i,j);
        }
        return;

    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<n-3;i++)
        {
            for(int j=i+1;j<n-2;j++)
            {
                int sum = target - nums[i] - nums[j];
                int low = j+1; 
                int high = n-1;
                findPossiblequas(nums,sum,low,high,i,j);
            }
        }
        for(auto i:s)
        {
            ans.push_back(i);
        }
        return ans;
    }
};