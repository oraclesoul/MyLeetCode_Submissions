class Solution {
public:
    string getPermutation(int n, int k) {
        string st;
        for(int i=1;i<=n;i++)
        {
            st+=char('0'+i);
        }
        for(int i=0;i<k-1;i++) next_permutation(st.begin(),st.end());
        return st;
    }
};