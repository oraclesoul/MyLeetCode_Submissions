class Solution {
public:
    int MOD = 1e9+7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
        vector< pair< int , int > > v;
        for(int i=0;i<n;i++) v.push_back({efficiency[i],speed[i]});
        sort(v.rbegin(),v.rend());

        priority_queue< int , vector< int > , greater< int >  > pq;

        long long res = 0;
        long long sum = 0;
        for(auto i:v)
        {
            pq.push(i.second);
            sum+=i.second;
            if(pq.size()>k)
            {
                sum -= pq.top();
                pq.pop();
            }
            res = max(res,sum*i.first);
        }

        return res%MOD;
        

    }
};