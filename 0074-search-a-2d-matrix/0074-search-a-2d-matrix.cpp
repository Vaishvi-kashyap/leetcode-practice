class Solution {
public:
    bool helperBinarySearch(vector<vector<int>>& matrix, int row, int tar) {
        int n = matrix[0].size(), st = 0, end = n - 1;
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (tar == matrix[row][mid])
                return true;
            else if (tar > matrix[row][mid])
                st = mid + 1;
            else
                end = mid - 1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int tar) {
        int m = matrix.size(), n = matrix[0].size(), st = 0, end = m - 1;
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (tar >= matrix[mid][0] && tar <= matrix[mid][n - 1])
                return helperBinarySearch(matrix, mid, tar);
            else if (tar > matrix[mid][n - 1])
                st = mid + 1;
            else
                end = mid - 1;
        }
        return false;
    }
};