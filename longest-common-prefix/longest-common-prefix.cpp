class Solution {
public:
   string common(string &a,string &b)
   {
       int n = a.length() , m = b.length();
       for(int i=0;i<max(n,m);i++)
       {
           if(i==n || i==m || a[i]!=b[i])
           {
               return string(a.begin(),a.begin()+i);
           }
       }
       return a;    
   }
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        for(int i=1;i<strs.size();i++)
        {
            ans = common(ans,strs[i]);
        }
        return ans;
    }
};