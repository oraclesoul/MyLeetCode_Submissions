    class Solution {
    public:
        int subarraySum(vector<int>& nums, int k) {
            // keep modulo count except   ( when sum is 0)
            int n = nums.size();
            vector< int > prefix;
            for(auto i:nums)
            {
                if(prefix.empty()) prefix.push_back(i);
                else prefix.push_back(prefix.back()+i);
            }

            unordered_map< int , int > mp;
            mp[0]=1;
            int cnt =0 ;
          
            for(auto i:prefix)
            {
                cnt+=mp[i-k];
                mp[i]++;
            }
            return cnt;

        }
    };