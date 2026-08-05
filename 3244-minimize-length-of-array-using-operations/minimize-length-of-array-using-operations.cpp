class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());

        int cnt = 0;
        for (int x : nums) {
            if (x == mn) cnt++;
            else if (x % mn != 0)
                return 1;
        }

        return (cnt + 1) / 2;
    }
};