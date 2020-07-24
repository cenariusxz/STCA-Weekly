class Solution {
    typedef long long ll;
public:
    int maximum(int a, int b) {
        return (int) (((ll)a + b + abs((ll)a - b)) / 2); 
    }
};
