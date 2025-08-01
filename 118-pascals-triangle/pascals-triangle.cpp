class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for (int n = 1; n <= numRows; n++) {
            vector<int> row;
            row.push_back(1);
            int value = 1;
            for (int c = 1; c < n; c++) {
                value = value * (n - c);
                value /= c;
                row.push_back(value);
            }
            ans.push_back(row);
        }

        return ans;
    }
};