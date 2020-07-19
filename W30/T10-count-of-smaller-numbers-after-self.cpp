class Solution {
    #define PB push_back
public:
    vector<int> tmp, ans, c;
    map<int, int>M;

    inline int lowbit(int x){return x&(-x);}

    void add(int x, int n){
        for(int i=x;i<=n;i+=lowbit(i))c[i]++;
    }

    int sum(int x){
        int ans=0;
        for(int i=x;i>0;i-=lowbit(i))ans+=c[i];
        return ans;
    }

    vector<int> countSmaller(vector<int>& nums) {
        if(nums.size() == 0)return nums;
        for(int i = 0 ; i < nums.size() ; ++ i)tmp.PB(nums[i]);
        sort(tmp.begin(), tmp.end());
        int cnt = 1;
        for(int i = 1 ; i < tmp.size() ; ++ i){
            if(tmp[i] != tmp[i-1])tmp[cnt ++] = tmp[i];
        }
        for(int i = 0 ; i < cnt ; ++ i)M[tmp[i]] = i+1;
        for(int i = 0 ; i < cnt + 5 ; ++ i)c.PB(0);

        for(int i = 0 ; i < nums.size() ; ++ i)ans.PB(0);
        for(int i = nums.size() - 1 ; i >= 0 ; -- i){
            ans[i] = sum(M[nums[i]] - 1);
            add(M[nums[i]], cnt);
        }
        return ans;
    }
};
