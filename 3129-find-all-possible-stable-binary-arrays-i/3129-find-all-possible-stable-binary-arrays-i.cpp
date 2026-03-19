
class Solution {
public:
int MOD = 1e9 + 7;
vector<vector<vector<int>>>dp;
    int numberOfStableArrays(int zero, int one, int limit) {
        dp.assign(zero + 1,vector<vector<int>>(one + 1,vector<int>(2,0)));
       dp[0][0][0] = dp[0][0][1] = 1; //base case

       for(int zeros = 0;zeros <= zero;zeros++)
       {
        for(int ones = 0;ones <= one;ones++)
        {
            if(zeros == 0 && ones == 0) continue;

            int res = 0;//explore 0
            for(int len = 1;len <=limit && zeros - len >= 0;len++)
            {
            res = (res + dp[zeros - len][ones][0]) % MOD;
            }
            dp[zeros][ones][1] = res;//lastwasone = true (1)

            res = 0;//explore 1's
            for(int len = 1;len <= limit && ones - len >= 0;len++)
            {
            res = (res + dp[zeros][ones - len][1]) % MOD;
            }
            dp[zeros][ones][0] = res;//lastwasone = false (0)
        }
       }

       return (dp[zero][one][0] + dp[zero][one][1]) % MOD; 
    }
};