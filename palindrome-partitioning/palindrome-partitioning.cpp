class Solution {
public:
    vector<vector<string>>ans;
    vector<string>v;
    
    bool isPali(string &s)
    {
        int n = s.length();
        for(int i=0;i<n;i++)
        {
            if(s[i]!=s[n-1-i]) return false;
        }
        return true;
    }
    
    void findAllPart(string &s,int index)
    {
        if(index<0)
        {
            ans.push_back(v);            
        }
        string st;
        for(int i=index;i>=0;i--)
        {
            st+=s[i];
            if(isPali(st))
            {
                v.push_back(st);
                findAllPart(s,i-1);
                v.pop_back();
            }
        }
        return;
    }
    
    
    vector<vector<string>> partition(string s) {
        reverse(s.begin(),s.end());
        findAllPart(s,s.length()-1);
        return ans;
    }
};