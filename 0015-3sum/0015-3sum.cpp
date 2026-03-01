class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        return threesum(nums,0,0);
    }
    vector<vector<int>> twosum(vector<int> &nums,int target,int si,int ei)
    {
        vector<vector<int>> ans;
        int n = nums.size();
        while(si < ei)
        {
            int sum = nums[si] + nums[ei];
            if(sum == target)
            {
                ans.push_back({nums[si],nums[ei]});
                si++;
                ei--;
                while(si < ei && nums[si] == nums[si - 1]) si++;                
                while(si < ei && nums[ei] == nums[ei + 1]) ei--;                

            }
            else if(sum < target)
            {
                si++;
            }
            else
            {
                ei--;
            }
        }
        return ans;
    }
     void addEleInList(vector<vector<int>> &res,vector<vector<int>> &ans, int data) {
        if (ans.size() == 0 || ans[0].size() == 0)
            return;

        for (auto sa : ans) {
          res.push_back({data,sa[0],sa[1]});
        }

    }

    vector<vector<int>> threesum(vector<int>& nums,int target,int si)
    {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        int n = nums.size(),i = si;
        while(i < n)
        {
            vector<vector<int>> pairs = twosum(nums,target - nums[i],i + 1, n - 1);
            addEleInList(res,pairs,nums[i]);
            i++;
            while (i < n && nums[i - 1] == nums[i])
                i++;

        }
        return res;
    }
};