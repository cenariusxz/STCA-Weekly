class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int t = m ^ n;
        while(m && (m & -m) <= t)m &= ~ (m & -m);
        return m;
    }
};
