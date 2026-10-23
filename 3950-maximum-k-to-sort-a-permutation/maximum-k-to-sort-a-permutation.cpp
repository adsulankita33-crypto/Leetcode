
class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;
        bool sorted = true;

        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                sorted = false;
                ans &= nums[i];
            }
        }

        if (sorted) {
            return 0;
        }

        return ans;
    }
};
