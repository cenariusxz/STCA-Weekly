class Solution {
    #define PB push_back
public:
    int getnum(string s, int st, int ed){
        int num = 0;
        for(int i = st ; i <= ed ; ++ i){
            num = num * 10 + s[i] - '0';
        }
        return num;
    }
    void get(string s, int &id, int &flag, int &t){
        int pos1 = -1, pos2 = -1;
        for(int i = 0 ; i < s.length() ; ++ i){
            if(s[i] == ':'){
                if(pos1 == -1)pos1 = i;
                else pos2 = i;
            }
        }
        id = getnum(s, 0, pos1-1);
        flag = s[pos1+1] == 's';
        t = getnum(s, pos2+1, s.length()-1);
    }
    stack<int>sta;
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        int pre = -1;
        vector<int> ans;
        ans.clear();
        for(int i = 0 ; i < n ; ++ i)ans.PB(0);
        for(int i = 0 ; i < logs.size(); ++ i){
            int id, flag, t;
            get(logs[i], id, flag, t);
            t -= flag;
            if(flag){       // st
                if(!sta.empty())ans[sta.top()] += t - pre;
                sta.push(id);
            }
            else{           // ed
                ans[id] += t - pre;
                sta.pop();
            }
            pre = t;
        }
        return ans;
    }
};
