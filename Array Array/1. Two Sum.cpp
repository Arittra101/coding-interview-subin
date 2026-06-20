class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> track;
        for (int i = 0; i < nums.size(); i++) {
            int rest = target - nums[i];
            if (track.contains(rest)) {
                return { track[rest], i};
            }

            track[nums[i]]=i;
        }

        return {};
    }
};