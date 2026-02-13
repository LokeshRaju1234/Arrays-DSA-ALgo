class Solution {
public:
    int mySqrt(int num) {
         long long l = 1,h = num / 2;
       
        while(l <= h)
        {
            long long mid = l + (h - l) / 2;
            if(mid * mid == num)
            {
                return mid;
            }
            else if(mid * mid < num)
            {
                l = mid + 1;
            }
            else
            {
                h = mid - 1;
            }
        }

        return h;
    }
};