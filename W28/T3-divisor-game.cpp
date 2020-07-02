class Solution {
public:
    bool dp[1005];
    bool divisorGame(int N) {
        dp[1] = 0;  // loss
        dp[2] = 1;  // win
        for(int i = 2 ; i <= N ; ++ i){
            for(int j = 1 ; j * j <= N ; ++ j){
                if(i % j)continue;
                if(j < i && dp[i-j] == 0)dp[i] = 1;
                if(i/j < i && dp[i-i/j] == 0)dp[i] = 1;
                if(dp[i])break;
            }
        }
        return dp[N];
    }
};