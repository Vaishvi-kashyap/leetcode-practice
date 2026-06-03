class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        int n = landStartTime.size();
        int m = waterStartTime.size();

        vector<pair<int, int>> land, water;

        for (int i = 0; i < n; i++)
            land.push_back({landStartTime[i], landDuration[i]});

        for (int i = 0; i < m; i++)
            water.push_back({waterStartTime[i], waterDuration[i]});

        sort(land.begin(), land.end());
        sort(water.begin(), water.end());

        vector<int> landStarts(n), waterStarts(m);

        for (int i = 0; i < n; i++)
            landStarts[i] = land[i].first;
        for (int i = 0; i < m; i++)
            waterStarts[i] = water[i].first;

        // Prefix min durations
        vector<int> landPrefMinDur(n);
        vector<int> waterPrefMinDur(m);

        landPrefMinDur[0] = land[0].second;
        for (int i = 1; i < n; i++)
            landPrefMinDur[i] = min(landPrefMinDur[i - 1], land[i].second);

        waterPrefMinDur[0] = water[0].second;
        for (int i = 1; i < m; i++)
            waterPrefMinDur[i] = min(waterPrefMinDur[i - 1], water[i].second);

        // Suffix min(start + duration)
        vector<int> landSufMin(n);
        vector<int> waterSufMin(m);

        landSufMin[n - 1] = land[n - 1].first + land[n - 1].second;
        for (int i = n - 2; i >= 0; i--)
            landSufMin[i] =
                min(landSufMin[i + 1], land[i].first + land[i].second);

        waterSufMin[m - 1] = water[m - 1].first + water[m - 1].second;
        for (int i = m - 2; i >= 0; i--)
            waterSufMin[i] =
                min(waterSufMin[i + 1], water[i].first + water[i].second);

        long long ans = LLONG_MAX;

        // Land -> Water
        for (int i = 0; i < n; i++) {
            long long T = (long long)landStartTime[i] + landDuration[i];

            int pos = upper_bound(waterStarts.begin(), waterStarts.end(), T) -
                      waterStarts.begin() - 1;

            if (pos >= 0)
                ans = min(ans, T + waterPrefMinDur[pos]);

            if (pos + 1 < m)
                ans = min(ans, (long long)waterSufMin[pos + 1]);
        }

        // Water -> Land
        for (int i = 0; i < m; i++) {
            long long T = (long long)waterStartTime[i] + waterDuration[i];

            int pos = upper_bound(landStarts.begin(), landStarts.end(), T) -
                      landStarts.begin() - 1;

            if (pos >= 0)
                ans = min(ans, T + landPrefMinDur[pos]);

            if (pos + 1 < n)
                ans = min(ans, (long long)landSufMin[pos + 1]);
        }

        return (int)ans;
    }
};