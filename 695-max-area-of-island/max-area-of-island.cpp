class Solution {
public:
    int m, n;

    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0)
            return 0;

        grid[i][j] = 0; // Mark as visited

        return 1 +
               dfs(grid, i + 1, j) +
               dfs(grid, i - 1, j) +
               dfs(grid, i, j + 1) +
               dfs(grid, i, j - 1);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    ans = max(ans, dfs(grid, i, j));
                }
            }
        }

        return ans;
    }
};