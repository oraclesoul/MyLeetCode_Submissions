class Solution {
public:
    vector<int>v;
    set<vector<int>>s;
    void findAllSubset(vector<int>& nums,int i)
    {
        if(i<0)
        {   
            vector<int>temp(v);
            sort(temp.begin(),temp.end());
            
            s.insert(temp);
            temp.clear();
            return;
        }
        
        findAllSubset(nums,i-1);
        v.push_back(nums[i]);
        findAllSubset(nums,i-1);
        v.pop_back();
        return;
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        findAllSubset(nums,nums.size()-1);
        
        vector<vector<int>>ans;
        for(auto i:s) ans.push_back(i);
        return ans;
        
    }
};