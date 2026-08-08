class Solution {
public:
    unordered_map<string,int> memo;
    string eliminate(string s) {
        while (true) {
            string t;
            bool changed = false;
            for (int i = 0; i < s.size();) {
                int j = i;
                while (j < s.size() && s[j] == s[i])
                    j++;
                if (j - i >= 3)
                    changed = true;
                else
                    t += s.substr(i, j - i);
                i = j;
            }
            if (!changed)
                return s;
            s = t;
        }
    }
    int dfs(string board, string hand) {
        board = eliminate(board);
        if (board.empty())
            return 0;
        if (hand.empty())
            return 6;
        string key = board + "#" + hand;
        if (memo.count(key))
            return memo[key];
        int ans = 6;
        for (int i = 0; i < hand.size(); i++) {
            if (i > 0 && hand[i] == hand[i - 1])
                continue;
            char ball = hand[i];
            string newHand = hand.substr(0, i) + hand.substr(i + 1);
            for (int j = 0; j <= board.size(); j++) {
                bool useful = false;
                if (j < board.size() && board[j] == ball)
                    useful = true;
                if (j > 0 && j < board.size() && board[j - 1] == board[j])
                    useful = true;
                if (!useful)
                    continue;
                string newBoard = board.substr(0, j) + ball + board.substr(j);
                ans = min(ans, 1 + dfs(newBoard, newHand));
            }
        }
        return memo[key] = ans;
    }
    int findMinStep(string board, string hand) {
        sort(hand.begin(), hand.end());
        int ans = dfs(board, hand);
        return ans == 6 ? -1 : ans;
    }
};