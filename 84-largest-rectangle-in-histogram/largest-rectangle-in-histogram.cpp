class Solution {
public:
    void solve(vector<int>& arr, vector<int>& prev, vector<int>& next) {
        int n = arr.size();
        stack<int> st;

        // Previous Smaller
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            prev[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty())
            st.pop();

        // Next Smaller
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            next[i] = st.empty() ? n : st.top();
            st.push(i);
        }
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> prev(n), next(n);

        solve(heights, prev, next);

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int width = next[i] - prev[i] - 1;
            ans = max(ans, heights[i] * width);
        }

        return ans;
    }
};