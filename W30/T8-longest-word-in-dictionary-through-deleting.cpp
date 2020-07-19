class Solution {
public:
    bool check(string &s, string &t){
        int n = s.length(), m = t.length(), pos = 0;
        for(int i = 0 ; i < m ; ++ i){
            while(s[pos] != t[i] && pos+1 < n)pos++;
            if(s[pos] == t[i])pos++;
            else return 0;
        }
        return 1;
    }
    static bool cmp(string a, string b){
        if(a.length() == b.length())return a < b;
        return a.length() > b.length();
    }
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(), cmp);
        //string ans = "";
        for(int i = 0 ; i < d.size() ; ++ i){
            if(check(s, d[i]))return d[i];
        }
        return "";
    }
};
