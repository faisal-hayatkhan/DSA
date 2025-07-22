class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        if(n == 1 && m == 1) {
            return grid[0][0];
        }

        vector<vector<int>> dp(n + 1, vector<int> (m + 1, INT_MAX));

        dp[0][0] = grid[0][0];

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(i == 0 && j == 0) {
                    continue;
                }

                int left = (i - 1 >= 0) ? dp[i - 1][j] : INT_MAX;
                int up = (j - 1 >= 0) ? dp[i][j - 1] : INT_MAX;

                dp[i][j] = grid[i][j] + min(left, up);

            }
        }

        return dp[n - 1][m - 1];
    }
};