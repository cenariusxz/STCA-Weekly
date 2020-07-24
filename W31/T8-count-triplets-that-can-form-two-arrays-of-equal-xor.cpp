class Solution {
public:
    int xorsum[305];
    int countTriplets(vector<int>& arr) {
        int ans = 0;
        for(int i = 0 ; i < arr.size() ; ++ i)xorsum[i+1] = xorsum[i] ^ arr[i];
        for(int i = 0 ; i < arr.size() ; ++ i){
            for(int k  = i + 1 ; k < arr.size() ; ++ k){
                if(xorsum[i-1+1] != xorsum[k+1])continue;
                ans += k - i;
            }
        }
        return ans;
    }
};
