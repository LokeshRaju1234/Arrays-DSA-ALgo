
class Solution {
public:
int MOD = 1e9 + 7;
    int numberOfStableArrays(int zero, int one, int limit) {
        int startwith0 = solve(zero,one,false,limit);
        int startwith1 = solve(zero,one,true,limit);
        return (startwith0 + startwith1) % MOD;
    }

    int solve(int zero,int one,bool lastWasone,int limit)
    {
        if(zero == 0 && one == 0)
        {
            return 1;
        }

        int res = 0;
        if(lastWasone)//explore 0's
        {
            for(int len = 1;len <= min(zero,limit);len++)
            {
            res = (res + solve(zero - len,one,false,limit)) % MOD;
            }
        }
        else //explore 1's
        {
            for(int len = 1;len <= min(one,limit);len++)
            {
            res = (res + solve(zero,one - len,true,limit)) % MOD;
            }
        }

        return res;
    }
};