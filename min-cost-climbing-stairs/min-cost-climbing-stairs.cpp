class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector< int > v(cost);
        v.push_back(0);
        for(auto i:v) cout<<i<<" "; cout<<endl;
        int n = cost.size();
        for(int i=2;i<=n;i++)
        {
            v[i] = v[i]+min(v[i-1],v[i-2]);  // min cost can be from last or from last to last step
        }
        return v[n];      
    }
};