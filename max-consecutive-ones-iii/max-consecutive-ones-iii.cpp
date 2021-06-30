class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
         int n = nums.size();
         int l = 0 ,r = 0;
         int ans = 0;
         while(r<n)
         {  
            if(l>r) r++;
            else if(nums[r]==1) r++;
            else if(k>0)
            {
               nums[r] = -1;
               r++;
               k--;
            }else
            {
               if(nums[l]==-1)
               {
                  k++;
                  nums[l] = 0;
               }
               l++;
            }

            ans = max(ans,r-l);
            
         }      
         ans = max(ans,r-l);
         return ans;
    }
};