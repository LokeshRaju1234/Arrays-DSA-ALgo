class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>prefix(n);
        vector<int>suffix(n);

        prefix[0] = 1;
        for(int i = 1;i < n;i++)
        {
            if(nums[i] <= nums[i - 1])
            {
                prefix[i] = prefix[i - 1] + 1;
            }
            else
            {
                prefix[i] = 1;//not possible it is not in non-decreasing order
            }
        }

        suffix[n - 1] = 1;
        for(int i = n - 2;i >= 0;i--)
        {
            if(nums[i] <= nums[i + 1])//if the curr num is less than the after ele so it is in non decreasing order
            {
                suffix[i] = suffix[i + 1] + 1;
            }
            else
            {
                suffix[i] = 1;//not possible it is not in non-decreasing order
            }
        }

        vector<int>ans;

        for(int i = 0;i < n;i++)
        {
            if(i - k >= 0 && i + k < n && prefix[i - 1] >= k && suffix[i + 1] >= k)
            {
                ans.push_back(i);
            } 
        }

        return ans;
    }
};