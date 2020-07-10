class Solution {
public:
    string removeOuterParentheses(string S) {
        int num = 0;
        string res = "";
        for(int i = 0 ; i < S.length() ; ++ i){
            if(S[i] == '('){
                if(num)res += S[i];
                num ++;
            }
            else{
                num --;
                if(num)res += S[i];
            }
        }
        return res;
    }
};
