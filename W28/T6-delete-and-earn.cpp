class Solution {
public:
    static const int maxm = 1e4 + 5;
    int a[maxm], dp[maxm][2];

    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0 ; i < n ; ++ i)a[nums[i]] += nums[i];
        for(int i = 1 ; i <= 10000 ; ++ i){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = dp[i-1][0] + a[i];
        }
        return max(dp[10000][0], dp[10000][1]);
    }
};
