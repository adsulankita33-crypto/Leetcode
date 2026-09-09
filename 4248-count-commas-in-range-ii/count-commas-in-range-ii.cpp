class Solution {
public:
    long long countCommas(long long n) {
        long long total_commas = 0;
        long long threshold = 1000;
        
        // Loop through comma thresholds: 1,000, 1,000,000, 1,000,000,000, etc.
        while (threshold <= n) {
            total_commas += (n - threshold + 1);
            
            // Prevent potential overflow if threshold * 1000 exceeds long long max
            if (threshold > LLONG_MAX / 1000) {
                break;
            }
            threshold *= 1000;
        }
        
        return total_commas;
    }
};
