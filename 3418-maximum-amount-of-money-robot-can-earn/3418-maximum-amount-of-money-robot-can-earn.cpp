class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        const int m = coins.size(), n = coins[0].size();
        vector<vector<long long>> dp(m, vector<long long>(n));
        vector<vector<long long>> temp(m, vector<long long>(n));
        temp[m - 1][n - 1] = coins[m - 1][n - 1];
        for(int i = m - 1; i >= 0; --i)
            for(int j = n - 1; j >= 0; --j){
                if (i == m - 1 && j == n - 1) continue;
                long long val = LLONG_MIN;
                if (i < m - 1) val = max(val, coins[i][j] + temp[i+1][j]);
                if (j < n - 1) val = max(val, coins[i][j] + temp[i][j+1]);
                temp[i][j] = val;
            }
        for(int k = 0; k < 2; ++k){
            dp[m-1][n-1] = (coins[m-1][n-1] < 0? 0 : coins[m-1][n-1]);
            for(int i = m - 1; i >= 0; --i)
                for(int j = n - 1; j >= 0; --j){
                    if (i == m - 1 && j == n - 1) continue;
                    long long val = LLONG_MIN;
                    int aCur = coins[i][j];
                    int cur = (aCur < 0? 0 : coins[i][j]);
                    if (i < m - 1) val = max(val, cur + temp[i+1][j]);
                    if (j < n - 1) val = max(val, cur + temp[i][j+1]);
                    if (i < m - 1) val = max(val, aCur + dp[i+1][j]);
                    if (j < n - 1) val = max(val, aCur + dp[i][j+1]);
                    dp[i][j] = val;
                }
            temp = dp;
        } return dp[0][0];
    }
};