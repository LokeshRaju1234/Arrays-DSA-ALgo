// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1,h = n;
        while(l < h)
        {
            int mid = l + (h - l) / 2;

            if(isBadVersion(mid))
            {
              h = mid;//the first bad version we encountered till now so we move high
            }
            else
            {
                l = mid + 1;
            }
        }

        return h;
    }
};