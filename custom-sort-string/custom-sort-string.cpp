int val[26];
bool comp(char a,char b)
{
  return val[a-'a']<val[b-'a'];
}
class Solution {
public:
    string customSortString(string order, string str) {
        // int val[26];
        memset(val,0,sizeof(val));
        
        for(int i=0;i<order.size();i++)
        {
          val[order[i]-'a']=i+1;
        }
       
        int k = order.size();
        for(int i=0;i<26;i++)
        {
          if(val[i]==0)
          {
            val[i] = k;
            k++;
          }
        }
        
        sort(str.begin(),str.end(),comp);
        return str;
    }
};