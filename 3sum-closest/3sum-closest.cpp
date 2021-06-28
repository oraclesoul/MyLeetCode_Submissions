class Solution {
public:
   int threeSumClosest(vector<int>& nums, int target) {
      sort(nums.begin(),nums.end());
      int closest = INT_MAX;
      int n = nums.size();
      int ans = 0;
      for(int i=0;i<n-2;i++)
      {
         int l = i+1;
         int r = n-1;
         while(l<r)
         {
            if(nums[i]+nums[r]+nums[l]<target)
            {
               if(closest>abs(target-nums[i]-nums[r]-nums[l]))
               {
                  ans = nums[i]+nums[r]+nums[l];
                  closest = abs(target-nums[i]-nums[r]-nums[l]);
                  cout<<nums[i]<<" "<<nums[l]<<" "<<nums[r]<<endl;               }
               l++;
            }else
            {
               if(closest>abs(target-nums[i]-nums[r]-nums[l]))
               {
                  ans = (nums[i]+nums[r]+nums[l]);
                  closest = abs(target-nums[i]-nums[r]-nums[l]);
                  cout<<nums[i]<<" "<<nums[l]<<" "<<nums[r]<<endl;               

               }
               r--;
            }
            
         }
         
      }   
      return ans;
      
   }
};
