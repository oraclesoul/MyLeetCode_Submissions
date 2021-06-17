class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        priority_queue< pair< int , int > > pq;
        for(int i=0;i<k-1;i++) pq.push({nums[i],i});
        vector< int > ans;
        for(int i=k-1;i<nums.size();i++)
        {
            pq.push({nums[i],i});
            while(pq.top().second<=(i-k))
            {
                pq.pop();
            }
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};