class Solution {
public:
int findNextAvailable(int low,int high,int currEnd,vector<vector<int>>& rides)
{
    int ans = -1;

    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        if(currEnd <= rides[mid][0])
        {
            ans = mid;
            high = mid - 1;
        }else
        {
            low = mid + 1;
        }
    }
    return ans;
}

long long rec(int i,vector<vector<int>> &rides,vector<long long> &dp,int n)
{
    if(i == n)
    {
        return 0;//if it reaches the end
    }

    if(dp[i] != -1)
    {
        return dp[i];
    }

    long long skip = rec(i + 1,rides,dp,n);
    long long take = rides[i][1] - rides[i][0] + rides[i][2];//profit i can get

    int currEnd = rides[i][1];
    int j = findNextAvailable(i + 1,n - 1,currEnd,rides);

    if(j != -1)
    {
        take += rec(j,rides,dp,n);
    }

    long long ans = max(take,skip);
    return dp[i] = ans;

}
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) 
    {
       int size = rides.size();
        vector<long long>dp(size + 1,-1);
        sort(rides.begin(),rides.end());
        return rec(0,rides,dp,size);
    }
};