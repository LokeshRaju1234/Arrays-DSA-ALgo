class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        unordered_map<int,int>toggle;

        for(int x : bulbs)
        {
            if(toggle[x] == 0) toggle[x]++;
            else toggle[x]--;
        }
        vector<int>ans;

        for(auto &p : toggle)
        {
            if(p.second == 1)
            {
                ans.push_back(p.first);
            }
        }

        return ans;
    }
};