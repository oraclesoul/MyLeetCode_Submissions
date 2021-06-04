class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int n = horizontalCuts.size();
        int m = verticalCuts.size();
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        int MOD = 1e9+7;
        int lst=0;
        int hmax=0;
        for(auto i:horizontalCuts)
        {
            hmax = max(hmax , i-lst);
            lst = i;
        }      
        hmax = max(hmax,h-lst);

        lst = 0;
        int vmax = 0;
        for(auto i:verticalCuts)
        {
            vmax = max(vmax,i-lst);
            lst = i;
        }
        vmax = max(vmax,w-lst);
        int ans = ((long long int)(hmax) * vmax)%MOD;
        return ans;
    }
};