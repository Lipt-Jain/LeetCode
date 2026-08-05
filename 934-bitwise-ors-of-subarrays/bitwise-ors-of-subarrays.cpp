class Solution {
public:
    int subarrayBitwiseORs(vector<int>& nums) {

        unordered_set<int> ans;
        unordered_set<int> cur, nxt;

        for (int x : nums) {
            nxt.clear();
            nxt.insert(x);
            for (int y : cur)
                nxt.insert(y | x);
            cur = nxt;
            for (int y : cur)
                ans.insert(y);
        }
        return ans.size();
    }
};