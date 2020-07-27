class Solution {
public:
    int multiply(int A, int B) {
        int ans = 0, tmp = A;
        while(B){
            if(B & 1)ans += tmp;
            tmp = (int)((long long)tmp + tmp);
            B >>= 1;
        }
        return ans;
    }
};
