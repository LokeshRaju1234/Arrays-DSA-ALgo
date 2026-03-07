class Solution {
public:
    int findNextAvailableEvent(int l,int h,vector<vector<int>>& events,int currEnd)
    {
        int ans = -1;

        while(l <= h)
        {
            int mid = l + (h - l) / 2;

            if(currEnd < events[mid][0])//checking that I can choose this event or not 
            {
                ans = mid;
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        return ans;
    }

    long long rec(int i,vector<vector<int>>& events,vector<vector<long long>> &dp,int k,int n)
    {
        if(i == n || k == 0)
        {
            return 0;//when it reaches end
        }

        if(dp[i][k] != -1)
        {
            return dp[i][k];
        }
        long long notTake = rec(i + 1,events,dp,k,n);
        long long take = events[i][2];

        int currEnd = events[i][1];

        //finding next available events that i can take
        int j = findNextAvailableEvent(i + 1,n - 1,events,currEnd);

        if(j != -1)//found next position that i can take
        {
            take += rec(j,events,dp,k - 1,n);//taking this event and red no of even i can take
        }

        long long ans = max(take,notTake);
        return dp[i][k] = ans;
    }
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(),events.end());
        vector<vector<long long>>dp(n + 1,vector<long long>(k + 1,-1));
        return rec(0,events,dp,k,n);
    }
};