class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> suf(m + 1, n);

        int i = n - 1;

        for (int j = m - 1; j >= 0; j--) {
            while (i >= 0 && word1[i] != word2[j]) {
                i--;
            }

            if (i < 0) {
                suf[j] = -1;
            } else {
                suf[j] = i;
                i--;
            }
        }

        vector<int> ans;
        bool usedMismatch = false;
        int pos = 0;

        for (int j = 0; j < m; j++) {

            while (pos < n) {

                if (word1[pos] == word2[j]) {
                    ans.push_back(pos);
                    pos++;
                    break;
                }

                if (!usedMismatch) {

                    bool possible = false;

                    if (j == m - 1) {
                        possible = true;
                    }
                    else if (suf[j + 1] != -1 &&
                             pos < suf[j + 1]) {
                        possible = true;
                    }

                    if (possible) {
                        usedMismatch = true;
                        ans.push_back(pos);
                        pos++;
                        break;
                    }
                }

                pos++;
            }
        }

        if ((int)ans.size() != m)
            return {};

        int mismatchCount = 0;

        for (int k = 0; k < m; k++) {
            if (word1[ans[k]] != word2[k])
                mismatchCount++;
        }

        if (mismatchCount > 1)
            return {};

        return ans;
    }
};