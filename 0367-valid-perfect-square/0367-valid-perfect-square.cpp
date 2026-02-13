class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 0,h = num / 2;
        if(num == 1)
        {
            return true;
        }
        while(l <= h)
        {
            int mid = l + (h - l) / 2;
            if(mid * mid == num)
            {
                return true;
            }
            else if(l < num)
            {
                l = mid + 1;
            }
            else
            {
                h = mid - 1;
            }
        }

        return false;
    }
};