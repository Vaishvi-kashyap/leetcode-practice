class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ops = 0;
        for (int x : nums) {
            if (x % 3 != 0)
                ops += 1; // one operation to fix each
        }
        return ops;
    }
};