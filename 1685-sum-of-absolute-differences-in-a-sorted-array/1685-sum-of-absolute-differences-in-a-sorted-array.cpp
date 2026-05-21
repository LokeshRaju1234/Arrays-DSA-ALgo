class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        long totalSum = 0;
        for(int num : nums)
        {
            totalSum += num;
        }

        long prefixSum = 0;

        for(int i = 0;i < n;i++)
        {
            long suffix = totalSum - prefixSum - nums[i];
            long left = (long) nums[i] * i - prefixSum;
            long right = suffix - (long) nums[i] * (n - i - 1);
            ans[i] = (int) (left + right);
            prefixSum += nums[i];
        }

        return ans;
    }
};