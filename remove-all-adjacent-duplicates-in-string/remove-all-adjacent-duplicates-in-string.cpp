class Solution {
public:
    string removeDuplicates(string s) {
        vector<char>v;
        for(auto i:s)
        {
          if(v.empty() || v.back()!=i) v.push_back(i);
          else v.pop_back();
        }
        string ans;
        for(auto i:v) ans+=i;
        return ans;
        
    }
};