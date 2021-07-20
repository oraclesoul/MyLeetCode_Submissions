class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
       int n = heights.size();
       stack<pair< int  , int > > stk;
       vector< int > lft,rht(n);
       for(int i=0;i<n;i++)
       {
          while(!stk.empty() && stk.top().first>=heights[i])
          {
             stk.pop();
          }
          if(stk.empty())
          {
             lft.push_back(-1);
          }else
          {
             lft.push_back(stk.top().second);
          }
          stk.push({heights[i],i});
       }

       while(!stk.empty()) stk.pop();
       
       for(int i=n-1;i>=0;i--)
       {
          while(!stk.empty() && stk.top().first>=heights[i])
          {
             stk.pop();
          }
          if(stk.empty())
          {
             rht[i] = n;
          }else
          {
             rht[i] = stk.top().second;
          }
          stk.push({heights[i],i});
       }


       int mxarea = 0;
       for(int i=0;i<n;i++)
       {
          cout<<lft[i]<<" "<<rht[i]<<endl;
         
          mxarea = max(mxarea,(rht[i]-lft[i]-1)*heights[i]);
       }
       return mxarea;
    }
};