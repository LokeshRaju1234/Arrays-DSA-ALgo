class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        bool bulbs1[101] = {0};//keep all bulbs off

        for(int x : bulbs)
        {
         bulbs1[x] = !bulbs1[x];   
        }

        vector<int>ans;

        for(int i = 0;i < 101;i++)
        {
            if(bulbs1[i] == 1) ans.push_back(i);
        }
        return ans;
    }
};