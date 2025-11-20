class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        // Sort by end increasing; if tie, start decreasing
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            if (a[1] == b[1])
                return a[0] > b[0];
            return a[1] < b[1];
        });

        int a = -1, b = -1; // last two chosen numbers
        int ans = 0;

        for (auto& in : intervals) {
            int start = in[0], end = in[1];

            bool a_in = (a >= start && a <= end);
            bool b_in = (b >= start && b <= end);

            if (a_in && b_in) {
                // Already have 2 numbers inside interval
                continue;
            } else if (a_in || b_in) {
                // One number inside → need 1 more
                ans += 1;
                // Pick the largest possible: end
                if (a_in) {
                    b = end;
                } else {
                    a = end;
                }
            } else {
                // No numbers inside → need 2 numbers
                ans += 2;
                // Pick end-1, end
                a = end - 1;
                b = end;
            }
        }

        return ans;
    }
};