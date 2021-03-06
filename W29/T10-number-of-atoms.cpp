class Solution {
    typedef pair<int, int> pii;
public:
    struct node{
        string name;
        int num;
    }nd[1005];
    map<string, int> M;
    int match[1005], cnt;
    stack<int> sta;
    static bool cmp(node a, node b){
        return a.name < b.name;
    }

    int getnum(string &s, int st, int ed){
        int num = 0;
        for(int i = st ; i <= ed ; ++ i){
            num = num * 10 + s[i] - '0';
        }
        return num;
    }

    void dfs(string &s, int st, int ed, int mul){
        for(int i = st; i <= ed ; ++ i){
            int pst = i, ped = i;
            if(s[i] >= 'A' && s[i] <= 'Z'){
                ped = match[i];
                string name = s.substr(pst, ped - pst + 1);
                if( !M[name] )M[name] = ++cnt;
                int id = M[name];
                nd[id].name = name;

                int m2 = 1;
                if(ped + 1 <= ed && s[ped + 1] >= '0' && s[ped + 1] <= '9'){
                    m2 = getnum(s, ped+1, match[ped+1]);
                    ped = match[ped+1];
                }
                nd[id].num += mul * m2;
            }
            if(s[i] == '('){
                ped = match[i];

                int m2 = 1;
                if(ped + 1 <= ed && s[ped + 1] >= '0' && s[ped + 1] <= '9'){
                    m2 = getnum(s, ped+1, match[ped+1]);
                    ped = match[ped+1];
                }
                dfs(s, pst+1, match[i]-1, mul * m2);
            }
            i = ped;
        }
    }
    
    string countOfAtoms(string formula) {
        for(int i = 0 ; i < formula.size() ; ++ i){
            if(formula[i] == '(')sta.push(i);
            if(formula[i] == ')'){
                int ma = sta.top(); sta.pop();
                match[ma] = i;
                match[i] = ma;
            }
        }

        int low = -1;
        for(int i = formula.size() - 1 ; i >= 0 ; -- i){
            if(formula[i] >= 'A' && formula[i] <= 'Z'){
                if(low == -1)match[i] = i;
                else match[i] = low;
                low = -1;
            }
            if(formula[i] >= 'a' && formula[i] <= 'z' && low == -1)low = i;
        }

        int num = -1;
        for(int i = formula.size() - 1 ; i >= 0 ; -- i){
            if(formula[i] >= '0' && formula[i] <= '9'){
                if(num == -1)num = i;
                match[i] = num;
            }
            else num = -1;
        }

        dfs(formula, 0, formula.size() - 1, 1);

        sort(nd + 1, nd + 1 + cnt, cmp);
        string ans = "";
        for(int i = 1 ; i <= cnt ; ++ i){
            ans += nd[i].name;
            if(nd[i].num > 1)ans += to_string(nd[i].num);
        }
        return ans;
    }
};
