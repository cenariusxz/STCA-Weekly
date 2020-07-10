class Solution {
    #define PB push_back
public:
    stack<int> sta;
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int pos = 1;
        for(int i = 0 ; i < target.size() ; ++ i){
            while(pos < target[i]){
                res.PB("Push");
                res.PB("Pop");
                pos++;
            }
            res.PB("Push");
            pos++;
        }
        return res;
    }
};
