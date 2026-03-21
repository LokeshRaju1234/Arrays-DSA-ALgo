class Solution {
public:
const int MOD = 1e9 + 7;
    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<vector<int>>>dp(zero + 1,vector<vector<int>>(one + 1,vector<int>(2,0)));
        //base cases
        for(int i = 0;i <= min(zero,limit);i++)
        {
            dp[i][0][0] = 1;//when there is only i zeroes and 0 ones
        }
        for(int j = 0;j <= min(one,limit);j++)
        {
            dp[0][j][1] = 1;//when there is only j ones and 0 zeroes
        }

        for(int i = 1;i <= zero;i++)
        {
            for(int j = 1;j <= one;j++)
            {
                //for invalid sequences there will be invalid sequences so we need to remove them if the sequence become limit + 1 O's or 1's
                long invalid0 = (i - limit >= 1) ? dp[i - limit - 1][j][1] : 0;//the invalid sequence will starts with 1 so remove the limit + 1 O's
                long invalid1 = (j - limit >= 1) ? dp[i][j - limit - 1][0] : 0;//the invalid sequence will starts with 0 so remove the limit + 1 1's
                //taking all prev sequences and appending 0 to the sequences and removing the invalid sequences which has limit + 1 sequences like if limit = 2 
                //-->1000  wrong voilates limit so we need to remove them by i - (limit + 1 ones or zeroes)
                dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][1] - invalid0 + MOD) % MOD;
                dp[i][j][1] = (dp[i][j - 1][0] + dp[i][j - 1][1] - invalid1 + MOD) % MOD;
            }
        }

        return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
    }
};