class Solution {
    void dfs(int row, int col, int initColor, int newColor,
             vector<vector<int>>& image) {

        image[row][col] = newColor;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        int n = image.size();
        int m = image[0].size();

        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (nrow >= 0 && nrow < n &&
                ncol >= 0 && ncol < m &&
                image[nrow][ncol] == initColor &&
                image[nrow][ncol] != newColor) {

                dfs(nrow, ncol, initColor, newColor, image);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc, int color) {

        int initColor = image[sr][sc];

        if (initColor == color)
            return image;

        dfs(sr, sc, initColor, color, image);

        return image;
    }
};