class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);

        // Count frequency of each character
        for (char ch : word) {
            freq[ch - 'a']++;
        }

        // Sort frequencies in descending order
        sort(freq.begin(), freq.end(), greater<int>());

        int ans = 0;

        // First 8 letters -> 1 push
        // Next 8 letters -> 2 pushes
        // Next 8 letters -> 3 pushes
        // Remaining -> 4 pushes
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) break;

            ans += freq[i] * (i / 8 + 1);
        }

        return ans;
    }
};