class Solution {
public:
    int bitwiseComplement(int n) {
        int mask = n;

        if(n == 0) return 1;

        mask  = (1 << (32 - __builtin_clz(n)) ) - 1;
        return mask ^ n;
    }
};