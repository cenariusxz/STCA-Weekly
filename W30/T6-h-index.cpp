class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.size() == 0)return 0;
        sort(citations.begin(), citations.end(), greater<int>());
        int ans = 0;
        for(int i = 0 ; i < citations.size() ; ++ i){
            int cnt = i + 1;
            if(cnt >= citations[i])ans = max(ans, citations[i]);
            else ans = max(ans, cnt);
        }
        return ans;
    }
};
