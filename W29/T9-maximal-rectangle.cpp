class Solution {
    #define PB push_back
public:
    vector<int> tmp, we;
    stack<int> sta;
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0)return 0;
        int n = matrix.size(), m = matrix[0].size(), ans = 0;
        for(int i = 0 ; i < n ; ++ i)tmp.PB(0), we.PB(0);
        for(int j = 0 ; j < m ; ++ j){
            for(int i = 0 ; i < n ; ++ i){
                we[i] = 0;
                if(matrix[i][j] == '1')tmp[i]++;
                else tmp[i] = 0;
            }
        
            for(int i = 0 ; i < n ; ++ i){
                while(!sta.empty() && tmp[sta.top()] >= tmp[i]){
                    we[sta.top()] += i - sta.top() - 1;
                    sta.pop();
                }
                if(sta.empty())we[i] += i+1;
                else we[i] += i-sta.top();
                sta.push(i);
            }
            while(!sta.empty()){
                we[sta.top()] += n-1 - sta.top();
                sta.pop();
            }
            for(int i = 0 ; i < n ; ++ i)ans = max(ans, tmp[i] * we[i]);
        }
        return ans;
    }
};
