class Solution {
    #define PB push_back
public:
    stack<int> sta, sta2;
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        ans.clear();
        for(int i = 0 ; i < asteroids.size(); ++ i){
            if(asteroids[i] > 0)sta.push(asteroids[i]);
            else{
                bool flag = 1;
                while(!sta.empty() && flag){
                    if(sta.top() < -asteroids[i])sta.pop();
                    else if(sta.top() == -asteroids[i]){
                        sta.pop();
                        flag = 0;
                    }
                    else flag = 0;
                }
                if(flag)ans.PB(asteroids[i]);
            }
        }
        while(!sta.empty()){
            sta2.push(sta.top());
            sta.pop();
        }
        while(!sta2.empty()){
            ans.PB(sta2.top());
            sta2.pop();
        }
        return ans;
    }
};
