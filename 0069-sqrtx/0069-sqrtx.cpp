class Solution {
public:
    int mySqrt(int num) {
       int ans = 0;

       for(int bits = 15;bits >= 0;bits--)
       {
        long  temp = ans | (1LL << bits);//ensures overflow
        if(temp * temp <= num)//if the square eqyual to the num then we can add it to res
        {
            ans = temp;
        }
       }

       return ans;
    }
};