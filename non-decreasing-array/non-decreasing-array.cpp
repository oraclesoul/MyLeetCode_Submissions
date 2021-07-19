class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i=0;i<n-1;i++)
        {
           if(nums[i]>nums[i+1])
           { 
             if(cnt>0)
             {
               return false;
             }
             cnt++;
             int prev;
             if(i==0)
             {
               prev = -1e5;
             }else prev = nums[i-1];
             
             if(nums[i+1]<prev)
             {
               nums[i+1] = nums[i];
             }else
             {
               nums[i] = prev;
             }
           }
        }
      return true;
    }
};