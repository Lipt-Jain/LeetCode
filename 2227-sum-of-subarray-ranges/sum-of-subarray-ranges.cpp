class Solution {
public:
    long long solve(vector<int>& arr, bool isMin) {
        int n = arr.size();

        vector<int> prev(n), next(n);
        stack<int> st;

        // Previous Smaller/Greater
        for (int i = 0; i < n; i++) {
            while (!st.empty() &&
                  (isMin ? arr[st.top()] > arr[i]
                         : arr[st.top()] < arr[i])) {
                st.pop();
            }

            prev[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Smaller/Greater
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() &&
                  (isMin ? arr[st.top()] >= arr[i]
                         : arr[st.top()] <= arr[i])) {
                st.pop();
            }

            next[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            long long left = i - prev[i];
            long long right = next[i] - i;
            ans += 1LL * arr[i] * left * right;
        }

        return ans;
    }

    long long sumSubarrayMins(vector<int>& arr) {
        return solve(arr, true);
    }

    long long sumSubarrayMaxs(vector<int>& arr) {
        return solve(arr, false);
    }

    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }
};