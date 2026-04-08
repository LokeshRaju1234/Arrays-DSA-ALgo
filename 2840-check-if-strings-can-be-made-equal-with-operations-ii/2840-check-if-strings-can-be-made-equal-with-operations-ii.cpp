class Solution {
public:
    bool checkStrings(string s1, string s2) 
    {
      //i will check all characters at even indices and odd indices if it matches then we can make s1 -> s2

      vector<int>even1(28,0);   
      vector<int>even2(28,0);   
      vector<int>odd1(28,0);   
      vector<int>odd2(28,0);
      int n = s1.length();
      for(int i = 0;i < n;i++)
      {
        if((i % 2) == 0)
        {
            //increase the char freq in both
            even1[s1[i] - 'a']++;
            even2[s2[i] - 'a']++;
        }
        else
        {
            odd1[s1[i] - 'a']++;
            odd2[s2[i] - 'a']++;
        }
      }

      for(int i = 0;i < 26;i++)
      {
        //if the characters freq in both string doesnt matches then we cant make s1--> s2
        //because even pos can only bt swappped with even indices and vice versa
        if(even1[i] != even2[i])
        {
            return false;
        }

        if(odd1[i] != odd2[i])
        {
            return false;
        }
      }

      return true;   
    }
};