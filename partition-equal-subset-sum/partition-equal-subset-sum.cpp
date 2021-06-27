class Solution {
public:
    bool canPartition(vector<int>& nums) {
      int sum = accumulate(nums.begin(),nums.end(),0);
      bool dp[sum+1];
      if(sum%2) return false;
      memset(dp,false,sizeof(dp));
      dp[0] = true;
      for(auto i:nums)
      {
         for(int j=sum;j>=0;j--)
         {
            if(dp[j])
            {
               dp[j+i] = true;
            }
         }
      }

      for(int i=0;i<sum+1;i++)
      {
         if(dp[i] &&  2*i==sum) return true;
      }
      return false;

    }
};