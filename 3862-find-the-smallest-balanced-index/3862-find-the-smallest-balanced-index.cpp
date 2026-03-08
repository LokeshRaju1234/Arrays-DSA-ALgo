class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        
        int n = nums.size();
        //left prefix sum
        vector<long long>leftSum(n);

        leftSum[0] = 0;//if there is no left element
        for(int i = 1;i < n;i++)
        {
            leftSum[i] = leftSum[i - 1] + (long long)nums[i - 1];
        }

         vector<long long>suffix(n);

         suffix[n - 1] = 1;//if there is no element on right
         for(int i = n - 2;i >= 0;i--)
         {
            if(nums[i + 1] != 0 && suffix[i + 1] > LLONG_MAX / nums[i + 1])//checking overflow a * b > LLONG_MAX (simply writing as b > LLONG_MAX / a)
            {
                suffix[i] = LLONG_MAX;//if prod overflows
            }
            else
            {
             suffix[i] = suffix[i + 1] * (long long)nums[i + 1];
            }
         }

         for(int i = 0;i < n;i++)
         {
            if(leftSum[i] == suffix[i]) return i;
         }

         return -1;
    }
};