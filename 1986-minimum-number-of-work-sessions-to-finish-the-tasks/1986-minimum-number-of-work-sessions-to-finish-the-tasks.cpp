class Solution {
public:
    int minSessions(vector<int>& tasks, int sessionTime) 
    {
        int n = tasks.size();
        int N = 1<<n;//total number of subsets I will get
        vector<pair<int,int>>dp(N,{n + 1,0});//n + 1 sessions as worst case
        //may be we can get all tasks in different sessions

        dp[0] = {1,0};
        for(int mask = 0;mask < N;mask++)//tells you which tasks are finished
        {
            for(int i = 0;i < n;i++)//which task i need to do next
            {
                if(mask & (1<<i)) continue;//if the task is already done

                int newMask = mask | (1 << i);

                int sessions = dp[mask].first;
                int currTime = dp[mask].second;

                if(currTime + tasks[i] <= sessionTime)
                {
                    currTime += tasks[i];
                }
                else
                {
                    sessions++;//new session
                    currTime = tasks[i];
                }

                if(sessions < dp[newMask].first ||
                sessions == dp[newMask].first && currTime < dp[newMask].second)
                {
                    dp[newMask] = {sessions,currTime};
                }
            }
        }

      return  dp[N - 1].first;
    }
};