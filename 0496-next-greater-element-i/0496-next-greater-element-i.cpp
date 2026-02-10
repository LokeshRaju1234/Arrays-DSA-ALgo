class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>nge;
        stack<int>s;

        for(int x : nums2)
        {
            while(!s.empty() && s.top() < x) // increasing stack
            {
                nge[s.top()] = x;//storing the next greater element
                s.pop();//pops the element
            }
            s.push(x);
        }

        while(!s.empty())
        {
            nge[s.top()] = -1;//for rem ele there is no next greater element so  -1
            s.pop();
        }
        vector<int>arr(nums1.size());
        for(int i = 0;i  < arr.size();i++)
        {
            arr[i] = nge[nums1[i]];
        }

        return arr;
    }
};