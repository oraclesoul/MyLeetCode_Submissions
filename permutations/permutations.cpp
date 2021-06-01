class Solution {
public:
    vector< vector< int > > ans;
    void findAllPermu(vector< int > nums,int i)
    {
        if(i<0)
        {
            ans.push_back(nums);
            return;
        }
        for(int j=i;j>=0;j--)
        {
            swap(nums[i],nums[j]);
            findAllPermu(nums,i-1);
            swap(nums[i],nums[j]);
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        // to find in order
        sort(nums.begin(),nums.end());
        findAllPermu(nums,nums.size()-1);
        return ans;       
        
    }
};