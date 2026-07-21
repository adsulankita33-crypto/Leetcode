class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        string t = "1" + s + "1";
        int m = t.size();

        int totalOnes = 0;
        for (char c : s)
            if (c == '1')
                totalOnes++;

        int ans = totalOnes;

        vector<pair<char,int>> blocks;

        // Run Length Encoding
        for (int i = 0; i < m;) {
            int j = i;
            while (j < m && t[j] == t[i])
                j++;

            blocks.push_back({t[i], j - i});
            i = j;
        }

        for (int i = 1; i + 1 < blocks.size(); i++) {

            // Middle block must be 1's
            if (blocks[i].first != '1')
                continue;

            // Surrounded by 0's
            if (blocks[i - 1].first != '0')
                continue;

            if (blocks[i + 1].first != '0')
                continue;

            int leftZero = blocks[i - 1].second;
            int oneLen = blocks[i].second;
            int rightZero = blocks[i + 1].second;

            int gain = leftZero + rightZero;

            ans = max(ans, totalOnes + gain);
        }

        return ans;
    }
};