class Solution {
    typedef long long ll;
public:
    int dfs(int st, int n, ll k){
        if(n == 1)return st;
        if(k <= (1ll << (n-2)))return dfs(st, n-1, k);
        else return dfs(st ^ 1, n-1, k - (1ll << (n-2)));
    }
    int kthGrammar(int N, int K) {
        return dfs(0, N, K);
    }
};
