class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int cnt = 0;
        for(int i=0;i<n;i++)
        { 
          if(nums[i]>0)
          for(int j=i+1;j<n;j++)
          {  
             if(nums[j]<=0) break;
             auto low = upper_bound(nums.begin()+j+1,nums.end(),nums[j]-nums[i]);
             auto high = lower_bound(nums.begin()+j+1,nums.end(),nums[j]+nums[i]);
             cnt += (high-low);
          }
        }
      return cnt;
    }
};