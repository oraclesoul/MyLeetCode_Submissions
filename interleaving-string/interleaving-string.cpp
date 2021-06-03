class Solution {
public:
    int dp[100][100];

    bool isIL(string &s1,int i , string &s2 ,int j,  string &s3,int k )
    {
         if(i<0)
         {
             return s2.substr(0,j+1) == s3.substr(0,k+1);
         }
         if(j<0)
         {
            return s1.substr(0,i+1) == s3.substr(0,k+1);
         }
         
         if(dp[i][j]>-1)
         {
            if(dp[i][j]>0) return true;
            return false;
         }

         bool ans = false;
         if(s3[k]==s1[i] && s3[k]==s2[j])
         {
            ans = isIL(s1,i-1,s2,j,s3,k-1);
            ans = ans | isIL(s1,i,s2,j-1,s3,k-1);
         }else if(s1[i]==s3[k])
         {
            ans = isIL(s1,i-1,s2,j,s3,k-1);
         }else if(s3[k]==s2[j])
         {
            ans = isIL(s1,i,s2,j-1,s3,k-1);
         }else
         {
            ans = false;
         }

         if(ans) dp[i][j] = 1;
         else dp[i][j]=0;
         return ans;
    }

    bool isInterleave(string s1, string s2, string s3) {
         if(s1.length()+s2.length()!=s3.length()) return false;
         memset(dp,-1,sizeof(dp)); 
         bool ans = isIL(s1,s1.length()-1,s2,s2.length()-1,s3,s3.length()-1);
         return ans;      
    }
};