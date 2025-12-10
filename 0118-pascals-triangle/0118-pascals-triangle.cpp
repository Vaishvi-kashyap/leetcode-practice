class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if (numRows == 0) {
            return res;
        }
        res.push_back({1});
        if (numRows == 1) {
            return res;
        }

        for (int i = 1; i < numRows; i++) {
            vector<int> prevRow = res[i - 1];
            vector<int> row;
            row.push_back(1);
            for (int j = 0; j < i - 1; j++) {
                row.push_back(prevRow[j] + prevRow[j + 1]);
            }
            row.push_back(1);
            res.push_back(row);
        }
        return res;
    }
};