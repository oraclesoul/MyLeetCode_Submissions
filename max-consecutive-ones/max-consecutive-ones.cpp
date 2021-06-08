class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0;
        int ans = 0;
        for(auto i:nums)
        {
            if(i==1) cnt++;
            else
            {
                cnt = 0;
            }
            ans = max(ans,cnt);
        }
        return ans;
    }
};