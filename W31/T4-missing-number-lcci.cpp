class Solution {
    #define PB push_back
public:
    int missingNumber(vector<int>& nums) {
        int ans = 0, n = nums.size();
        if( (n + 1) / 2 & 1 )ans = 1;
        if(!(n & 1))ans ^= n;
        for(int i = 0 ; i < nums.size() ; ++ i)ans ^= nums[i];
        return ans;
    }
};
