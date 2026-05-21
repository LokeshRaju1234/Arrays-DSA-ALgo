class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int>prefix(n + 1,0);
        prefix[0] = 0;

        for(int i = 0;i < n;i++)
        {
            
                if(vowel(words[i]))
                {
                    prefix[i + 1] = prefix[i] + 1;
                }
                else
                {
                    prefix[i + 1]= prefix[i];
                }
            
        }

        vector<int>ans;
        for(const auto &query : queries)
        {
            int le = query[0];
            int ri = query[1];

            ans.push_back(prefix[ri + 1] - prefix[le]);
        }

        return ans;
    }

    bool vowel(string &word)
    {
        char st = word[0];
        char end = word[word.size() - 1];

       bool start_is_vowel = (st == 'a' || st == 'e' || st == 'i' || st == 'o' || st == 'u');
        bool end_is_vowel = (end == 'a' || end == 'e' || end == 'i' || end == 'o' || end == 'u');

        return start_is_vowel && end_is_vowel;
    }
};