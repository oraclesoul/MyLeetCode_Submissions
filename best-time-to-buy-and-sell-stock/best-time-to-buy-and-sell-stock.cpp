class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int mnprice = prices[0];
        int profit=0;
        for(auto i:prices)
        {   
            if(i>mnprice)
            profit = max(profit,i-mnprice);
            
            mnprice = min(mnprice,i);
        }
        return profit;
    }
};