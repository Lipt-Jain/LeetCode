class Solution {
public:
    static const int MOD = 1e9 + 7;

    int countOfPairs(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());

        vector<vector<int>> dp(n, vector<int>(mx + 1, 0));

        // Base
        for (int x = 0; x <= nums[0]; x++)
            dp[0][x] = 1;

        for (int i = 1; i < n; i++) {

            vector<int> prefix(mx + 1);
            prefix[0] = dp[i - 1][0];

            for (int j = 1; j <= mx; j++)
                prefix[j] = (prefix[j - 1] + dp[i - 1][j]) % MOD;

            for (int x = 0; x <= nums[i]; x++) {

                int limit = min(x, x + nums[i - 1] - nums[i]);

                if (limit >= 0)
                    dp[i][x] = prefix[limit];
            }
        }

        long long ans = 0;
        for (int x = 0; x <= nums[n - 1]; x++)
            ans = (ans + dp[n - 1][x]) % MOD;

        return ans;
    }
};