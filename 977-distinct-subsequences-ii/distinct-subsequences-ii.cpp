class Solution {
public:
    int distinctSubseqII(string s) {
        int MOD = 1e9 + 7;
        int n = s.length();
        
        // dp[i] stores the number of distinct subsequences of prefix s[0...i-1]
        vector<long long> dp(n + 1, 0);
        dp[0] = 1; // Base case: empty subsequence
        
        // Stores the last 1-based index where character 'a'-'z' was seen
        vector<int> last(26, -1);
        
        for (int i = 1; i <= n; ++i) {
            char ch = s[i - 1];
            
            // Appending current char doubles all previously formed distinct subsequences
            dp[i] = (2 * dp[i - 1]) % MOD;
            
            // Subtract duplicate subsequences created from the character's previous appearance
            if (last[ch - 'a'] != -1) {
                int prev_idx = last[ch - 'a'];
                dp[i] = (dp[i] - dp[prev_idx - 1] + MOD) % MOD;
            }
            
            // Update last seen position
            last[ch - 'a'] = i;
        }
        
        // Exclude the empty subsequence from the final count
        return (dp[n] - 1 + MOD) % MOD;
    }
};