class Solution {
public:
int findNextJobAvailable(int low,int high,int endTime,vector<vector<int>> &arr)
{
    int ans = -1;

    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        if(arr[mid][0] >= endTime)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}
int rec(int index,vector<vector<int>> &arr,vector<int> &dp,int n)
{
    if(index == n)
    {
        return 0;
    }

    if(dp[index] != -1)
    {
        return dp[index];
    }

    int skip = rec(index + 1,arr,dp,n);
    int take = arr[index][2];
    int currEndTime = arr[index][1];
    int j = findNextJobAvailable(index + 1,n - 1,currEndTime,arr);

    if(j != -1)
    {
        take += rec(j,arr,dp,n);
    }

    int ans = max(take,skip);
    return dp[index] = ans;
}
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<int>dp(n + 1,-1);
        vector<vector<int>>arr;
        for(int i = 0;i < n;i++)
        {
            arr.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(arr.begin(),arr.end());//so we can find overlappings
        return rec(0,arr,dp,n);
    }
};