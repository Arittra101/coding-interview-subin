class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1])continue;
            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k) {
                int sm = nums[i] + nums[j] + nums[k];

                if (sm > 0) k--;
                else if (sm < 0) j++;
                else {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    while (j < k && nums[j] == nums[j - 1]) j++;
                    while (j < k && nums[k] == nums[k + 1]) k--;
                }
            }
        
        
        }

        return ans;
    }
};


/*
Time Complexity: O(n^2) where n is the number of elements in the input array. The outer loop runs n times, and for each iteration, the inner while loop can run up to n times in the worst case.
Space Complexity: O(1) if we don't consider the space used for the output. The algorithm uses a constant amount of extra space for variables, regardless of the input size.
However, if we consider the space used for the output, it can be O(k), where k is the number of unique triplets found.


*/