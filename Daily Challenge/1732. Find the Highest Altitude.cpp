class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sm = 0;
        int mx = max(sm,INT_MIN);
        for (auto it : gain) {
            sm += it;
            mx = max(sm, mx);
        }
        return mx;
    }
};