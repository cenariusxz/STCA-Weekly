class Solution {
public:
    static const int INF = 0x3f3f3f3f;
    int dp[305][7][7][7][7];  //dp[i][x1][y1][x2][y2]  min cost after typed (i-1)-th letter and located at (x1, y1), (x2, y2);
    inline void getPos(char c, int &x, int &y){
        x = (c - 'A') / 6, y = (c - 'A') % 6;
    }
    inline int getDis(int x1, int y1, int x2, int y2){
        return abs(x1 - x2) + abs(y1 - y2);
    }
    int minimumDistance(string word) {
        int len = word.length();
        memset(dp, 0x3f, sizeof(dp));
        memset(dp[0], 0, sizeof(dp[0]));
        for(int i = 0 ; i < len ; ++ i){
            // i -> i+1
            int x, y;
            getPos(word[i], x, y);
            for(char p1 = 'A' ; p1 <= 'Z' ; ++ p1){
                int x1, y1, x2, y2;
                getPos(p1, x1, y1);
                for(char p2 = 'A' ; p2 <= 'Z' ; ++ p2){
                    getPos(p2, x2, y2);
                    dp[i+1][x][y][x2][y2] = min(dp[i+1][x][y][x2][y2], dp[i][x1][y1][x2][y2] + getDis(x1, y1, x, y));
                    dp[i+1][x1][y1][x][y] = min(dp[i+1][x1][y1][x][y], dp[i][x1][y1][x2][y2] + getDis(x2, y2, x, y));
                }
            }
        }
        int ans = INF;
        for(char p1 = 'A' ; p1 <= 'Z' ; ++ p1){
            int x1, y1, x2, y2;
            getPos(p1, x1, y1);
            for(char p2 = 'A' ; p2 <= 'Z' ; ++ p2){
                getPos(p2, x2, y2);
                ans = min(ans, dp[len][x1][y1][x2][y2]);
            }
        }
        return ans;
    }
};
