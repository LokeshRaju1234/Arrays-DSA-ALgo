class Solution {
public:
    int minOperations(string s) 
    {
        int n = s.size();
        string comp = s;
        
        sort(comp.begin(),comp.end());
        if(comp==s) return 0;//if the string is already sorted
        if(n == 2 && s[0] > s[1]) return -1;//impossible to sort

        int mn = 1000,mx = -1;
        for(auto x : s)
        {
            mn = min(mn,(int)x);
            mx = max(mx,(int)x);
        }
        //if first character is maximum and last is minimum so it takes 3 oper to sort in worst case
        if((int)s[0] == mx && (int)s[n - 1] == mn)
        {
            for(int i = 1;i < n - 1;i++)
            {
                if((int)s[i] == mn || (int)s[i] == mx) return 2;
            }
            return 3;
        }

        if((int)s[0] == mn || (int)s[n - 1] == mx) return 1;

        //for the case of If first is mx or if last is mn or any other case-> done in 2 operaations
        return 2;
        
    }
};