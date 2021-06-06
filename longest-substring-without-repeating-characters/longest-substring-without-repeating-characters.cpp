class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int n = s.length();
        int low = 0 , high = 0 ;
        unordered_map<char , bool > mp;
        while(high<n)
        {
            if(mp[s[high]])
            {
                mp[s[low]]=false;
                low++;
            }else
            {
                mp[s[high]]=true;
                high++;
                ans = max(ans,high-low);
            }
        }
        return ans;
    }
};