class Solution {
public:
    int longestSubstring(string s, int k) {

        int n = s.size();
        int maxLen = 0;

        for (int targetUnique = 1; targetUnique <= 26; targetUnique++) {

            int freq[26] = {0};
            int si = 0, ei = 0;
            int unique = 0;
            int countAtLeastK = 0;

            while (ei < n) {

                // expand window
                if (freq[s[ei] - 'a'] == 0)
                    unique++;

                freq[s[ei] - 'a']++;

                if (freq[s[ei] - 'a'] == k)
                    countAtLeastK++;

                ei++;

                // shrink window
                while (unique > targetUnique) {

                    if (freq[s[si] - 'a'] == k)
                        countAtLeastK--;

                    freq[s[si] - 'a']--;

                    if (freq[s[si] - 'a'] == 0)
                        unique--;

                    si++;
                }

                // check validity
                if (unique == targetUnique && unique == countAtLeastK)
                    maxLen = max(maxLen, ei - si);
            }
        }

        return maxLen;
    }
};