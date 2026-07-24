class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int it : asteroids) {

            bool destroyed = false;

            while (!st.empty() && st.top() > 0 && it < 0) {

                if (abs(st.top()) < abs(it)) {
                    st.pop();
                }
                else if (abs(st.top()) == abs(it)) {
                    st.pop();
                    destroyed = true;
                    break;
                }
                else {
                    destroyed = true;
                    break;
                }
            }

            if (!destroyed)
                st.push(it);
        }

        vector<int> ans;

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};