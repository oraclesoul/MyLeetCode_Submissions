
class Solution {
public:
   int lengthOfLIS(vector<int>& nums) {
      vector< int > dp;
      for(auto i:nums)
      {
         if(dp.empty() || dp.back()<i) dp.push_back(i);
         else
         {
            *(lower_bound(dp.begin(),dp.end(),i)) = i;
         }
      }
      return dp.size();

   }
};