class Solution {
public:
    map<int, int> M;
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(k == 0){
            for(int i = 0 ; i < nums.size() - 1 ; ++ i){
                if(nums[i] == 0 && nums[i+1] == 0)return 1;
            }
            return 0;
        }
        if(k < 0)k = -k;
        int sum = 0;
        M[sum] = 1;
        for(int i = 0 ; i < nums.size() ; ++ i){
            sum += nums[i];
            if(sum >= k) sum %= k;
            if(M[sum]){
                if(i+2 - M[sum] > 1)return 1;
            }
            else M[sum] = i+2;
        }
        return 0;
    }
};
