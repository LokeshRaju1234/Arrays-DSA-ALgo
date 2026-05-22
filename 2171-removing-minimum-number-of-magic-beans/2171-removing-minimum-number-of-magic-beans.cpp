class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(),beans.end());

        long sum = 0;
        for(int x : beans)
        {
            sum += x;
        }


        long ans = LONG_MAX;
        int n = beans.size();

        for(int i = 0;i < n;i++)
        {
            long keep = (long) beans[i] * (n - i);//keep means what ever the beans i need to keep
            ans = min(ans,sum - keep);
        }

        return ans;
    }
};