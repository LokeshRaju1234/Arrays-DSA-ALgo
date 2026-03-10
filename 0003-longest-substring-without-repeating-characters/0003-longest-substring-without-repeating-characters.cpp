class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ei = 0,si = 0,len = 0,count = 0;
        vector<int>freq(128,0);

        while(ei < s.size())
        {
            if(freq[s[ei++]]++ == 1) count++;

            while(count == 1)//invalid so shrink the window
            {
                if(freq[s[si++]]-- == 2) count--;//then it becomes unique
            }
            len = max(len,ei - si);
        }

        return len;
    }
};