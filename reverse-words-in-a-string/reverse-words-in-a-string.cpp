class Solution {
public:
    string reverseWords(string s) {
        
        vector< string > v;
        string st;
        for(int i=0;i<=s.length();i++)
        {
            if(i==s.length() || s[i]==' ')
            {
                if(st.size()>0)
                    v.push_back(st);
                
                st = "";
            }else
            {
                st+=s[i];
            }
        }
        
        string ans;
        
        
        while(v.size()>0)
        {
            ans+=v.back();
            ans+=' ';
            v.pop_back();
        }
       
        ans.pop_back();
        return ans;
        
    }
};