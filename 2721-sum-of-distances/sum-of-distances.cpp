class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;

        // Store indices for each value
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        vector<long long> ans(nums.size());

        for (auto &it : mp) {
            vector<int> &pos = it.second;
            int m = pos.size();

            vector<long long> prefix(m + 1, 0);

            // Prefix sums of indices
            for (int i = 0; i < m; i++)
                prefix[i + 1] = prefix[i] + pos[i];

            for (int i = 0; i < m; i++) {
                long long left =
                    1LL * pos[i] * i - prefix[i];

                long long right =
                    (prefix[m] - prefix[i + 1]) -
                    1LL * pos[i] * (m - i - 1);

                ans[pos[i]] = left + right;
            }
        }

        return ans;
    }
};