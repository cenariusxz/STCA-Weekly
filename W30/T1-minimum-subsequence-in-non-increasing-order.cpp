class Solution {
    #define PB push_back
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int sum = 0, tmp = 0;
        for(int i = 0 ; i < nums.size() ; ++ i)sum += nums[i];
        vector<int> ans;
        ans.clear();
        for(int i = 0 ; i < nums.size() ; ++ i){
            tmp += nums[i];
            ans.PB(nums[i]);
            if(tmp > sum - tmp)break;
        }
        return ans;
    }
};
