class Solution {
    typedef long long ll;
public:
    string decodeAtIndex(string S, int K) {
        ll len = 0;
        for(int i = 0 ; i < S.length() ; ++ i){
            if(S[i] >= '2' && S[i] <= '9'){
                if(len * (S[i] - '0') >= K)return decodeAtIndex(S.substr(0,i), (K-1)%len+1);
                len *= (S[i] - '0');
            }
            else{
                len++;
                if(len == K)return S.substr(i,1);
            }
        }
        return "";
    }
};
