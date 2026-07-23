class Solution {
public:
    vector<int> previousSmallerIndex(vector<int>& arr) {
        int n = arr.size();
        vector<int> prev(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            if (!st.empty())
                prev[i] = st.top();

            st.push(i);
        }

        return prev;
    }

    vector<int> nextSmallerIndex(vector<int>& arr) {
        int n = arr.size();
        vector<int> next(n, n);   // n instead of -1
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if (!st.empty())
                next[i] = st.top();

            st.push(i);
        }

        return next;
    }

    int sumSubarrayMins(vector<int>& arr) {
        long long sum = 0;
        int mod = 1e9 + 7;

        vector<int> prev = previousSmallerIndex(arr);
        vector<int> next = nextSmallerIndex(arr);

        for (int i = 0; i < arr.size(); i++) {
            long long left = i - prev[i];
            long long right = next[i] - i;

            sum = (sum + (1LL * arr[i] * left % mod) * right) % mod;
        }

        return sum;
    }
};