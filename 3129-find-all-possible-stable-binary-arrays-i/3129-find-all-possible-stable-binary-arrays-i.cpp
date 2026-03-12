class Solution {
public:
vector<vector<vector<int>>>dp;
int MOD = 1e9 + 7;
    int numberOfStableArrays(int zero, int one, int limit) 
    {
        dp.assign(zero + 1,vector<vector<int>>(one + 1, vector<int>(2,-1)));
        int startWithZero = solve(zero,one,1,limit);
        int startWithOne = solve(zero,one,0,limit);
        return (startWithZero + startWithOne) % MOD;
    }

    int solve(int zero,int one,int lastWasOne,int limit)
    {
        if(zero == 0 && one == 0)
        {
            return 1;
        }

        if(dp[zero][one][lastWasOne] != -1)
        {
            return dp[zero][one][lastWasOne];
        }
        long long res = 0;
        if(lastWasOne)//explore 0's
        {
            for(int len = 1;len <= min(zero,limit);len++)
            {
                res = (res + solve(zero - len,one,0,limit)) % MOD;
            }
        }
        else
        {
            for(int len = 1;len <= min(one,limit);len++)
            {
                res = (res + solve(zero,one - len,1,limit)) % MOD;
            }
        }

        return dp[zero][one][lastWasOne] = res;
    }
};