class Solution {
public:
    vector< vector< int > > v;
    
    bool isExist(string &a)
    {
        int idx = -1;
        for(auto i:a)
        {
            auto j = upper_bound(v[i-'a'].begin(),v[i-'a'].end(),idx);
            if(j==v[i-'a'].end()) return false;
            idx = *j;
        }
        return true;
    }
    
    int numMatchingSubseq(string s, vector<string>& words) {
        v.resize(26);
        
        for(int i=0;i<s.length();i++)
        {
            v[s[i]-'a'].push_back(i);
        }
       
        int cnt = 0;
        for(auto &i:words)
        {
            if(isExist(i)) cnt++;
        }
        return cnt;
        
    }
};