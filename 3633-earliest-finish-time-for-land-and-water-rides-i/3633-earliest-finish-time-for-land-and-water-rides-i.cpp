class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        int ans = INT_MAX;

        int n = landStartTime.size();
        int m = waterStartTime.size();

        for (int i = 0; i < n; i++) {
            int landFinish = landStartTime[i] + landDuration[i];

            for (int j = 0; j < m; j++) {
                int waterFinish = waterStartTime[j] + waterDuration[j];

                // Land -> Water
                ans = min(ans, max(waterStartTime[j], landFinish) +
                                   waterDuration[j]);

                // Water -> Land
                ans = min(ans,
                          max(landStartTime[i], waterFinish) + landDuration[i]);
            }
        }

        return ans;
    }
};