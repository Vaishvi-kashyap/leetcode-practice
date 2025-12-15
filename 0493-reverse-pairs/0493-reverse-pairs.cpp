class Solution {
public:
    // TC:O(nlogn)
    int revPairCount = 0;
    void mergeSort(vector<int>& nums, int st, int mid, int end) {
        int k = mid + 1; // Count reverse pairs before actual merge
        for (int i = st; i <= mid; i++) {
            while (k <= end && nums[i] > (long)2 * nums[k]) {
                k++;
            }
            revPairCount += k - (mid + 1);
        }

        vector<int> temp;
        int i = st, j = mid + 1;
        while (i <= mid && j <= end) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i]);
                i++;
            } else {
                temp.push_back(nums[j]);
                j++;
            }
        }
        while (i <= mid) {
            temp.push_back(nums[i]);
            i++;
        }
        while (j <= end) {
            temp.push_back(nums[j]);
            j++;
        }

        int idx = -1;
        for (int idx = 0; idx < temp.size(); idx++) {
            nums[st + idx] = temp[idx];
        }
    }

    void merge(vector<int>& nums, int st, int end) {
        int n = nums.size();
        int mid = st + (end - st) / 2;
        if (st < end) {
            merge(nums, st, mid);      // Left
            merge(nums, mid + 1, end); // Right

            mergeSort(nums, st, mid, end);
        }
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        merge(nums, 0, n - 1);
        return revPairCount;
    }
};