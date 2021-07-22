
class Solution {
public:
    char getD(pair<int,char>&a,pair<int,char>&b,int i)
    {  
       if(a.second == b.second) return a.second;
       if(a.second == 'L' && b.second=='R') return '.';
       if(a.second=='.' && b.second=='L') return b.second;
       if(a.second=='R' && b.second=='.') return a.second; 
       if(a.second=='L' && b.second=='.' || a.second=='.' && b.second=='R') return '.';
       if(abs(i-a.first)<abs(i-b.first)) return a.second;
       if(abs(i-a.first)>abs(i-b.first)) return b.second;
       
       return '.';

    }
    string pushDominoes(string v) {
        int n = v.size();
        vector< pair< int , char > > prefix(n),suffix(n);
        
        int idx=-1;
        char ch = '.';
        for(int i=0;i<n;i++)
        {
           if(v[i]=='L' || v[i]=='R')
           {
              prefix[i] = {i,v[i]};
              idx = i;
              ch = v[i];
           }else
           {
              prefix[i] = {idx,ch};
           }
        }
        idx = n;
        ch = '.';
        for(int i=n-1;i>=0;i--)
        {
           if(v[i]=='L' || v[i]=='R')
           {
              suffix[i] = {i,v[i]};
              idx = i;
              ch = v[i];
           }else
           {
              suffix[i] = {idx,ch};
           }
        }

        string ans;
        for(int i=0;i<n;i++)
        {
           ch = getD(prefix[i],suffix[i],i);
           ans.push_back(ch);
        }
        return ans;

    }
};