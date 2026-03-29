class Solution {
public:
    bool canBeEqual(string s1, string s2) 
    {
        //only we can swap is wiht the indices with even pos and odd pos 
        //s1 = "abcd", s2 = "cdab" -->only we can swap indices (0,2) and (1,3) which gives j - i = 2

        //check if string is already equal so we check --> s1[0] == s2[0] && s1[2] == s2[2])
        //case: s1 = abcd and s2 = abcd 
        bool evenpos = (s1[0] == s2[0] && s1[2] == s2[2]) ||
        (s1[0] == s2[2] && s1[2] == s2[0]);

        bool oddpos = (s1[1] == s2[1] && s1[3] == s2[3]) ||
        (s1[1] == s2[3] && s1[3] == s2[1]);

        return evenpos && oddpos;
    }
};