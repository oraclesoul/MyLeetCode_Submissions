class Solution {
public:
    int firstMissingPositive(vector<int>& A) {
      
      int n = A.size();
      int pos = 0;
      for(auto i:A) if(i>0) pos++;
      
      int l = 0 , r = n-1;
      while(l<r)
      {
        while(l<r && A[l]>0) l++;
        while(r>l && A[r]<=0) r--;
        if(l<r)
        {
          swap(A[l],A[r]);
        }
      }
      
      for(int i=0;i<pos;i++)
      { 
         if(abs(A[i])<=n)
         A[abs(A[i])-1] = - abs(A[abs(A[i])-1]);
      }
      for(int i=0;i<pos;i++)
      {
        if(A[i]>0) return i+1;
      }
      return pos+1;
        
        
    }
};