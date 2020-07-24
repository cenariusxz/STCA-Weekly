class Solution {
    #define PB push_back
public:
    map<string, int> M;
    map<string, int>::iterator it;
    vector<string> ans;
    vector<string> findRepeatedDnaSequences(string s) {
        for(int i = 0 ; i + 9 < s.length() ; ++ i){
            M[s.substr(i, 10)] ++;
        }
        for(it = M.begin() ; it != M.end() ; it ++){
            if((*it).second > 1)ans.PB((*it).first);
        }
        return ans;
    }
};
