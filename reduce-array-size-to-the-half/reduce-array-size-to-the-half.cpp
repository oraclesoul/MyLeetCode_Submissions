class Solution {
public:
    int minSetSize(vector<int>& arr) {
      
      vector< int > v(1e5+1,0);
      for(auto i:arr)v[i]++;
      sort(v.rbegin(),v.rend());

      int n = arr.size();
      int cnt = 0;
      int newn = n;
      for(auto i:v)
      {
         newn -= i;
         cnt++;
         if(newn<=n/2) break;
      }
      return cnt;
      
      return cnt;

    }
};