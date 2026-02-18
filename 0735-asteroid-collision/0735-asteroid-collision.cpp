class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;

        for (int val : asteroids) {
            while (!st.empty() && st.back() > 0 && val < 0) {
                if (st.back() < -val) {
                    st.pop_back();
                    continue;
                } else if (st.back() == -val) {
                    st.pop_back();
                }
                val = 0;
                break;
            }
            if (val != 0)
                st.push_back(val);
        }
        return st;
    }
};