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
        return 0;//if it reaches the end return 0 No further will be there
    }

    if(dp[i] != -1)
    {
        return dp[i];//avoiding recurring calls helps resuce T.C
    }

    long long skip = rec(i + 1,rides,dp,n);//skip and take the next customer bcz we dont know starting from this index we will get high profit
    long long take = rides[i][1] - rides[i][0] + rides[i][2];//profit i can get If i take the ride from customer

    int currEnd = rides[i][1];
    int j = findNextAvailable(i + 1,n - 1,currEnd,rides);//searching for non-Overlapping rides so that i can continue with that ride ->using Binary search i can eficienntly search for a ride with no overlaping rides

    if(j != -1)
    {
        take += rec(j,rides,dp,n);
    }

    long long ans = max(take,skip);
    return dp[i] = ans;//memoization

}
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) 
    {
       int size = rides.size();
        vector<long long>dp(size + 1,-1);
        sort(rides.begin(),rides.end());
        return rec(0,rides,dp,size);
    }
};