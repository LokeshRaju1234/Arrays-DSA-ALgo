class Solution {
public:
    int minSessions(vector<int>& tasks, int sessionTime) {

        int n = tasks.size();
        int N = 1 << n;

        vector<pair<int,int>> dp(N, {n+1, 0});
        dp[0] = {1,0};

        for(int mask = 0; mask < N; mask++)
        {
            for(int i = 0; i < n; i++)
            {
                if(mask & (1<<i)) continue;

                int newMask = mask | (1<<i);

                int sessions = dp[mask].first;
                int time = dp[mask].second;

                if(time + tasks[i] <= sessionTime)
                {
                    time += tasks[i];
                }
                else
                {
                    sessions++;
                    time = tasks[i];
                }

                if(sessions < dp[newMask].first ||
                  (sessions == dp[newMask].first && time < dp[newMask].second))
                {
                    dp[newMask] = {sessions,time};
                }
            }
        }

        return dp[N-1].first;
    }
};