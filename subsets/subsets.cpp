class Solution {
public:
    vector< vector < int > > ans;
    void findPowerSet(vector< int > &nums,int i, vector< int > &v)
    {
        if(i<0)
        {   
            ans.push_back(v);
            return;
        }
        findPowerSet(nums,i-1,v);
        v.push_back(nums[i]);
        findPowerSet(nums,i-1,v);
        v.pop_back();
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
       
        vector< int > v;
        findPowerSet(nums,nums.size()-1,v);
        return ans;
    }
};