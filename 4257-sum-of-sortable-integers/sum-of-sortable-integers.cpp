class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        // Check every divisor of n
        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool valid = true;
            int prevMax = -1;

            // Process each block of length k
            for (int start = 0; start < n; start += k) {
                int mn = nums[start];
                int mx = nums[start];
                int descents = 0;

                for (int j = start; j < start + k; j++) {
                    mn = min(mn, nums[j]);
                    mx = max(mx, nums[j]);

                    if (j > start && nums[j - 1] > nums[j])
                        descents++;
                }

                // Check the circular boundary
                if (nums[start + k - 1] > nums[start])
                    descents++;

                // Block cannot be sorted by cyclic rotation
                if (descents > 1) {
                    valid = false;
                    break;
                }

                // Blocks must be globally non-decreasing
                if (prevMax > mn) {
                    valid = false;
                    break;
                }

                prevMax = mx;
            }

            if (valid)
                ans += k;
        }

        return ans;
    }
};