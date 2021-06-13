class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0) return false;
        long long int a = n;
        return (a&a-1) == 0;
    }
};