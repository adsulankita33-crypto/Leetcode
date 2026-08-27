class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        vector<int> cnt(26, 0);

        for (char c : s) {
            cnt[c - 'a']++;
        }

        // Try to make prefix equal to target
        for (int i = 0; i < n; i++) {

            int x = target[i] - 'a';

            // If target[i] is available, use it
            if (cnt[x] > 0) {
                cnt[x]--;
                continue;
            }

            // target[i] is not available.
            // Find smallest character greater than target[i].
            for (int c = x + 1; c < 26; c++) {

                if (cnt[c] > 0) {

                    string ans = target.substr(0, i);
                    ans += char('a' + c);

                    cnt[c]--;

                    // Add remaining characters in sorted order
                    for (int j = 0; j < 26; j++) {
                        ans += string(cnt[j], char('a' + j));
                    }

                    return ans;
                }
            }

            break;
        }

        // We need to change an earlier position.
        fill(cnt.begin(), cnt.end(), 0);

        for (char c : s) {
            cnt[c - 'a']++;
        }

        // Try positions from right to left
        for (int i = n - 1; i >= 0; i--) {

            vector<int> temp = cnt;
            bool possible = true;

            // Match target[0 ... i-1]
            for (int j = 0; j < i; j++) {

                int x = target[j] - 'a';

                if (temp[x] == 0) {
                    possible = false;
                    break;
                }

                temp[x]--;
            }

            if (!possible)
                continue;

            int x = target[i] - 'a';

            // Find smallest character greater than target[i]
            for (int c = x + 1; c < 26; c++) {

                if (temp[c] > 0) {

                    string ans = target.substr(0, i);
                    ans += char('a' + c);

                    temp[c]--;

                    // Remaining characters in sorted order
                    for (int j = 0; j < 26; j++) {
                        ans += string(temp[j], char('a' + j));
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};