class Solution {
public:
    bool isSubsequence(string s, string t) {
        int lens = s.length(), lent = t.length(), pos = 0;
        for(int i = 0 ; i < lens ; ++ i){
            bool flag = 0;
            while(pos < lent){
                if(s[i] == t[pos ++]){
                    flag = 1;
                    break;
                }
            }
            if(!flag)return 0;
        }
        return 1;
    }
};