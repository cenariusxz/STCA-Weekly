class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0 = 0, p1 = 0, p2 = 0;
        for(int i = 0 ; i < nums.size() ; ++ i){
            if(nums[i] == 0){
                if(p1 && p2)nums[p0] = 0, nums[p0+p1] = 1, nums[i] = 2;
                else if(p1)nums[p0] = 0, nums[i] = 1;
                else if(p2)nums[p0] = 0, nums[i] = 2;
                p0 ++;
            }
            else if(nums[i] == 1){
                if(p2)nums[p0+p1] = 1, nums[i] = 2;
                p1 ++;
            }
            else p2 ++;
        }
    }
};
