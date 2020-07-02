class Solution {
public:
    static const int bs = 1 << (21);
    bool dp[bs];
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(desiredTotal <= maxChoosableInteger)return 1;
        if(maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal)return 0;
        for(int i = 0 ; i < (1 << (maxChoosableInteger)) ; ++ i){
            int sum = 0;
            for(int bit = 0 ; bit < maxChoosableInteger ; ++ bit){
                if(! (i & (1 << bit)))sum += bit+1;
            }
            if(sum >= desiredTotal)continue;

            for(int bit = 0 ; bit < maxChoosableInteger ; ++ bit){
                if(! (i & (1 << bit)))continue;
                int tmp = i - (1 << bit);
                if(dp[tmp] == 0)dp[i] = 1;
                if(dp[i])break;
            }
        }
        return dp[(1<<maxChoosableInteger)-1];
    }
};
