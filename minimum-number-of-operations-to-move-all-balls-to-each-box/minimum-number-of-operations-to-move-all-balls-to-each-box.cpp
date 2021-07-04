class Solution {
public:
    vector<int> minOperations(string boxes) {
      int n = boxes.size();
      vector<int>answer(n,0);
      for(int i=0;i<n;i++)
      {
         int cnt = 0;
         for(int j=i-1;j>=0;j--)
         {
            if(boxes[j]=='1') cnt += abs(j-i);
         }
         for(int j=i+1;j<n;j++)
         {
            if(boxes[j]=='1') cnt += abs(j-i);
         }
         answer[i] = cnt;
      }
      return answer;      
    }

};
