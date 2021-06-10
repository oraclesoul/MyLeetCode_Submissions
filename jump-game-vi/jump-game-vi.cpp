class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        int ans = nums[0];
        pq.push({nums[0],0});
        for(int i=1;i<nums.size();i++)
        {
            while((pq.top().second<(i-k)))
            {
                pq.pop();
            }
            int curr = nums[i]+pq.top().first;
            ans = curr;
            pq.push({curr,i});
        }
        return ans;
    }
};