class Solution {
public:
int sum(vector<int>& arr)
{
    int sum = 0;
    for(int e : arr)
    {
        sum += e;
    }
    return sum;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int capacity = *max_element(weights.begin(),weights.end());
        int maxRange = sum(weights);

        int l = capacity,h = maxRange;
        int ans = 0;
        while(l <= h)
        {
            int mid = l + (h - mid) / 2;
            int reqDays = required(weights,mid);
            if(reqDays <= days)
            {
                ans = mid;
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        return ans;
    }

    int required(vector<int>& arr,int cap)
    {
        int days = 1;
        int load = 0;
        for(int i = 0;i < arr.size();i++)
        {
            if(load + arr[i] > cap)//if greater this weight will be shipped to next day
            {
                load = arr[i];
                days++;//new day
            }
            else
            {
                load += arr[i];
            }
        }

        return days;
    }
};