class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector< pair< int , int > > v;
        for(int i=0;i<n;i++) v.push_back({nums[i],i});

        // using two pointer apporch
        sort(v.begin(),v.end()); // sort according to the value
        vector< int > ans;
        int low=0,high = n-1;
        while(low<high)
        {
            if(v[low].first+v[high].first==target)
            {
                ans.push_back(v[low].second);
                ans.push_back(v[high].second);
                return ans;
            }else if(v[low].first+v[high].first<target)
            {
                low++;
            }else
            {
                high--;
            }
        }
        return ans;
    }
};
