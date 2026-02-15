class Solution {
public:
    int almostPalindromic(string s) {
        int maxi = 2;//because if there is "ab" we can dlt one char and we will get 2 len
        int n = s.size();
        for(int i = 0;i < n;i++)
        {
            //for odd length palindrome
            //also checking I can include one char in my subarray after deleting an character by left side
            int l = i - 1;
            int r = i + 1;
            bool used = true;
            while(l >= 0 && r < n)
            {
                if(s[l] != s[r])
                {
                    if(used)
                    {
                        used = false;
                        l--;
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    maxi = max(maxi,r - l + 1);//length of the substring
                    if((r < n - 1 || l > 0) && used) //if I not removed one char also till now
                    {
                        maxi = max(maxi,r - l + 2);//I can take one mismatch character into substring 
                    }
                    l--;
                    r++;
                }
            }

            //for odd length palindrome
            //also checking I can include one char in my subarray after deleting an character by right side
            l = i - 1;
            r = i + 1;
            used = true;
            while(l >= 0 && r < n)
            {
                if(s[l] != s[r])
                {
                    if(used)
                    {
                        used = false;
                        r++;
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    maxi = max(maxi,r - l + 1);//length of the substring
                    if((r < n - 1 || l > 0) && used) //if I mot removed one char also till now
                    {
                        maxi = max(maxi,r - l + 2);//I can take one mismatch character into substring 
                    }
                    l--;
                    r++;
                }
            }

            //for EVEN LENGTH palindrome
            //also checking I can include one char in my subarray after deleting an character by left side
             l = i;
             r = i + 1;
             used = true;
            while(l >= 0 && r < n)
            {
                if(s[l] != s[r])
                {
                    if(used)
                    {
                        used = false;
                        l--;
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    maxi = max(maxi,r - l + 1);//length of the substring
                    if((r < n - 1 || l > 0) && used) //if I not removed one char also till now
                    {
                        maxi = max(maxi,r - l + 2);//I can take one mismatch character into substring 
                    }
                    l--;
                    r++;
                }
            }

            //for EVEN length palindrome
            //also checking I can include one char in my subarray after deleting an character by right side
             l = i;
             r = i + 1;
             used = true;
            while(l >= 0 && r < n)
            {
                if(s[l] != s[r])
                {
                    if(used)
                    {
                        used = false;
                        r++;
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    maxi = max(maxi,r - l + 1);//length of the substring
                    if((r < n - 1 || l > 0) && used) //if I mot removed one char also till now
                    {
                        maxi = max(maxi,r - l + 2);//I can take one mismatch character into substring 
                    }
                    l--;
                    r++;
                }
            }

        }

        return maxi;
    }
};