class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>s;
        for(auto i:nums) s.insert(i);
        int lst = -1e9-1;
        int ans = 0;
        int cnt = 0;
        for(auto i:s)
        {
            if(lst+1==i) cnt++;
            else
            {   
                cnt = 1;
            }
            ans = max(cnt,ans);
            lst = i;
        }      
        return ans;
    }
};