class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        stack<int>s;
        int n = nums.size();
        vector<int>arr(n, -1);

        for(int i = 0;i < 2 * n;i++)
        {
            int idx = i % n;
            while(!s.empty() && nums[s.top()] < nums[idx])
            {
                arr[s.top()] = nums[idx];
                s.pop(); 
            }

            if(i < n)
            {
                s.push(idx);
            }
        }
        return arr;
    }
};