class Solution {
public:
    static const int maxm = 1e4 + 5;
    int dp[2][maxm];
    int tallestBillboard(vector<int>& rods) {
        if(rods.size() < 2)return 0;
        int sum = 0;
        for(int i = 0 ; i < rods.size() ; ++ i)sum += rods[i];
        int half = sum /= 2;
        memset(dp, -1, sizeof(dp));
        dp[0][5000] = 0;
        for(int i = 0 ; i < rods.size() ; ++ i){
            int pre = i & 1;
            int now = pre ^ 1;
            memcpy(dp[now], dp[pre], sizeof(dp[now]));
            for(int j = 5000 - half ; j <= 5000 + half ; ++ j){
                if(dp[pre][j] == -1)continue;
                if(dp[pre][j] + rods[i] > dp[now][j+rods[i]])dp[now][j+rods[i]] = dp[pre][j] + rods[i];
                if(dp[pre][j] > dp[now][j-rods[i]])dp[now][j-rods[i]] = dp[pre][j];
            }
        }
        return dp[rods.size() & 1][5000];
    }
};
