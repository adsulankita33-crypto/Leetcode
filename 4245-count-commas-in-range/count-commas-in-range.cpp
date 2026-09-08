class Solution {
public:
    long long countCommas(int n) {
        long long total = 0;

        for (int i = 1; i <= n; i++) {
            int x = i;

            while (x >= 1000) {
                total++;
                x /= 1000;
            }
        }

        return total;
    }
};