class Solution {
public:
    vector<vector<int>>ans;
    vector<int>v;
    void findAllCombination(vector<int>& candidates,int i,int target)
    {
        if(target<0 || i<0) return;
        if(target==0)
        {
            ans.push_back(v);
            return;
        }
        v.push_back(candidates[i]);
        target-=candidates[i];
        findAllCombination(candidates,i,target);
        v.pop_back();
        target+=candidates[i];
        findAllCombination(candidates,i-1,target);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        findAllCombination(candidates,candidates.size()-1,target);
        return ans;
    }
};