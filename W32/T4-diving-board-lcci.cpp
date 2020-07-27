class Solution {
    #define PB push_back
public:
    vector<int>ans;
    vector<int> divingBoard(int shorter, int longer, int k) {
        if(k == 0)return ans;
        if(shorter == longer){
            ans.PB(k * shorter);
            return ans;
        }
        for(int i = 0 ; i <= k ; ++ i)ans.PB((k - i) * shorter + i * longer);
        return ans;
    }
};
