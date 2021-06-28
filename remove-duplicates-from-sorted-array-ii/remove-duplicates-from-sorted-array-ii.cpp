class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int n = nums.size();
       int l = 0,r = 0;
       while(r<n)
       {
          int cnt = 0;
          if(l>0 && nums[l-1]==nums[r]) cnt++;
          if(l>1 && nums[l-2]==nums[r]) cnt++;
          if(cnt<2)
          {
             nums[l] = nums[r];
             l++;
          }
          r++;
       }
       return l;
      
    }
};