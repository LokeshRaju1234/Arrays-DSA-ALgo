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
            j ^= 1;//toggle the bit and check if it matches it is in alternative sequence
        }

        //count will give gives you how many are alteratively moving and n - count gives the mismatch elements
        ans = min(count,n - count);
        return ans;
    }
};