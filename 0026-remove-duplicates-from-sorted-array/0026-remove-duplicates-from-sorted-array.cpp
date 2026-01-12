class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // We use two pointers: one to track the last unique element and another
        // to scan the array; when a new value is found, we overwrite the next
        // position.
        int n = nums.size();
        int i = 0;
        for (int j = 1; j < n; j++) {
            if (nums[i] != nums[j]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};