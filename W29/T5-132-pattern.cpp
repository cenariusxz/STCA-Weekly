class Solution {
public:
    static const int INF = 0x3f3f3f3f;
    stack<int> sta;
    bool find132pattern(vector<int>& nums) {
        bool flag = 0;
        int mx = 0;
        for(int i = nums.size() - 1 ; i >= 0 ; -- i){
            if(flag && nums[i] < mx)return 1;
            while(!sta.empty() && nums[i] > sta.top()){
                if(flag)mx = max(mx, sta.top());
                else flag = 1, mx = sta.top();
                sta.pop();
            }
            if(sta.empty() || nums[i] < sta.top()){
                sta.push(nums[i]);
                continue;
            }
        }
        return 0;
    }
};
