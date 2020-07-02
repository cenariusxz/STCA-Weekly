class Solution {
public:
    int r[105][105], d[105][105];
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int tmp = 0;
        for(int i = 0 ; i < n ; ++ i){
            tmp = 0;
            for(int j = m - 1 ; j >= 0 ; -- j){
                tmp = grid[i][j] ? tmp + 1 : 0;
                r[i][j] = tmp;
            }
        }
        for(int j = 0 ; j < m ; ++ j){
            tmp = 0;
            for(int i = n - 1 ; i >= 0 ; -- i){
                tmp = grid[i][j] ? tmp + 1 : 0;
                d[i][j] = tmp;
            }
        }
        int ans = 0;
        for(int i = 0 ; i < n ; ++ i){
            for(int j = 0 ; j < m ; ++ j){
                int mn = min(r[i][j], d[i][j]);
                if(mn <= ans)continue;
                for(int len = ans + 1 ; len <= mn ; ++ len){
                    if(r[i+len-1][j] >= len && d[i][j+len-1] >= len)ans = max(ans, len);
                }
            }
        }
        return ans * ans;
    }
};
