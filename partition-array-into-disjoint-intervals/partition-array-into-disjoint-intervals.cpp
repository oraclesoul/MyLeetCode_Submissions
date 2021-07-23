

class Solution {
public:
    struct comp
    {
      bool operator()(const pair<int,int>a,const pair<int,int>b)
      {
         if(a.first>b.first) return true;
         return false;
      }
    };
  
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
      
        priority_queue< pair<int,int> , vector<pair<int,int> > , comp > mnpq;
        for(int i=1;i<n;i++)
        {
          mnpq.push({nums[i],i});
        }
      
        int mx = nums[0];
        for(int i=1;i<n;i++)
        {
          while(!mnpq.empty() && mnpq.top().second<i) mnpq.pop();
          if(mx<=mnpq.top().first)
          {
            return i;
          }
          mx = max(mx,nums[i]);
        }
    
        return 1;
        
    }
};