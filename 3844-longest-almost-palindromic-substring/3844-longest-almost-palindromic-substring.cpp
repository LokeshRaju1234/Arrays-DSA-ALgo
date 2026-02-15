class Solution {
public:
    int almostPalindromic(string s) {
        int maxi = 2;

        int n = s.size();

        for (int i = 0; i < n; i++) {

            int j = i - 1;
            int k = i + 1;
            bool flag = true;
            while (j >= 0 && k < n) {
                if (s[j] != s[k]) {
                    if (flag) {
                        flag = false;
                        j--;
                    } else {
                        break;
                    }
                } else {
                    maxi = max(maxi, k - j + 1);
                    if ((k < n - 1 || j > 0) && flag) {
                        maxi = max(maxi, k - j + 2);
                    }
                    j--;
                    k++;
                }
            }

            j = i - 1;
            k = i + 1;
            flag = true;

            while (j >= 0 && k < n) {
                if (s[j] != s[k]) {
                    if (flag) {
                        flag = false;
                        k++;
                    } else {
                        break;
                    }
                } else {
                    maxi = max(maxi, k - j + 1);
                    if ((k < n - 1 || j > 0) && flag) {
                        maxi = max(maxi, k - j + 2);
                    }
                    j--;
                    k++;
                }
            }

            j = i;
            k = i + 1;
            flag = true;

            while (j >= 0 && k < n) {
                if (s[j] != s[k]) {
                    if (flag) {
                        flag = false;
                        j--;
                    } else {
                        break;
                    }
                } else {
                    maxi = max(maxi, k - j + 1);
                    if ((k < n - 1 || j > 0) && flag) {
                        maxi = max(maxi, k - j + 2);
                    }
                    j--;
                    k++;
                }
            }

            j = i;
            k = i + 1;
            flag = true;

            while (j >= 0 && k < n) {
                if (s[j] != s[k]) {
                    if (flag) {
                        flag = false;
                        k++;
                    } else {
                        break;
                    }
                } else {
                    maxi = max(maxi, k - j + 1);
                    if ((k < n - 1 || j > 0) && flag) {
                        maxi = max(maxi, k - j + 2);
                    }
                    j--;
                    k++;
                }
            }

          
        }
        return maxi;
    }
};