class Solution {
public:
    int minOperations(string s) {
        int count = 0;
        int j = 0;
        int ans = 0;
        int  n = s.size();
        for(int i = 0;i < n;i++)
        {
            if(s[i] - '0' == j) count++;//we got a match
            j ^= 1;
        }

        ans = min(count,n - count);
        return ans;
    }
};