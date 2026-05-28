class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0)
            return false;

        map<int, int> mp; //{nums,freq}
        for (int val : hand)
            mp[val]++;

        for (auto it : mp) {
            int start = it.first;
            int freq = it.second;

            if (freq == 0)
                continue;

            for (int i = 0; i < groupSize; i++) {
                int card = start + i;
                if (mp[card] < freq)
                    return false;
                mp[card] -= freq;
            }
        }
        return true;
    }
};