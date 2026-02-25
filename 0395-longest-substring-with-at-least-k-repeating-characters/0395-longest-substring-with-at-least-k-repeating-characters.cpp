class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        int len = 0;
        for(int targetUnique = 1;targetUnique <= 26;targetUnique++)
        {
            int freq[26] = {0};
            int unique = 0;
            int countAtleastk = 0;
            int ei = 0,si = 0;

            while(ei < n)
            {
                if(freq[s[ei] - 'a'] == 0) unique++;

                freq[s[ei]- 'a']++;

                if(freq[s[ei] - 'a'] == k) countAtleastk++;
                ei++;

                //shrink window when we get unique characters more than targetUnique
                while(unique > targetUnique)
                {
                    if(freq[s[si] - 'a'] == k) countAtleastk--;

                    freq[s[si] - 'a']--;

                    if(freq[s[si] - 'a'] == 0) unique--;//removing the character in window

                    si++;
                }

                if(unique == targetUnique && unique == countAtleastk
                )
                {
                    len = max(len,ei - si);
                }
            }

        }

        return len;
    }
};