class Solution {
public:
    int ans = 0;
    int target;

    void solve(int i, int cur, vector<int>& nums) {
        if (i == nums.size()) {
            if (cur == target)
                ans++;
            return;
        }

        // Don't take
        solve(i + 1, cur, nums);

        // Take
        solve(i + 1, cur | nums[i], nums);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        target = 0;

        for (int x : nums)
            target |= x;

        solve(0, 0, nums);

        return ans;
    }
};