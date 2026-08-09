class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0;
        int right = 0;
        int ans = 0;

        for (char c : s) {
            if (c == '(')
                left++;
            else
                right++;

            if (left == right)
                ans = max(ans, 2 * right);

            if (right > left) {
                left = 0;
                right = 0;
            }
        }

        left = right = 0;

        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '(')
                left++;
            else
                right++;

            if (left == right)
                ans = max(ans, 2 * left);

            if (left > right) {
                left = 0;
                right = 0;
            }
        }

        return ans;
    }
};