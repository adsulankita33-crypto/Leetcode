
class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long MOD = 1000000007;
        int count[31] = {0};

        // Step 1: Count set bits at every position
        for (int x : nums) {
            for (int bit = 0; bit < 31; bit++) {
                if (x & (1 << bit)) {
                    count[bit]++;
                }
            }
        }

        long long ans = 0;

        // Step 2: Construct k maximum numbers
        for (int i = 0; i < k; i++) {
            long long num = 0;

            for (int bit = 0; bit < 31; bit++) {
                if (count[bit] > 0) {
                    num |= (1LL << bit);
                    count[bit]--;
                }
            }

            // Step 3: Add square modulo MOD
            ans = (ans + num * num) % MOD;
        }

        return ans;
    }
};