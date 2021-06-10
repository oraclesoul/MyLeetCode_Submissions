class Solution {
public:
    
    set<vector<int>>s;
    vector<int>v;
    void findAllComb(vector<int>&candi,int i,int target)
    {
         if(target==0)
        {
            s.insert(v);
            return;
        }
        if(i<0 || target<0) return;
       
        findAllComb(candi,i-1,target);
        v.push_back(candi[i]);
        findAllComb(candi,i-1,target-candi[i]);
        v.pop_back();
        return;
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candi, int target) {
        sort(candi.begin(),candi.end());
        findAllComb(candi,candi.size()-1,target);
        
        vector<vector<int>>ans;
        for(auto i:s)
            ans.push_back(i);
        return ans;      
    }
};