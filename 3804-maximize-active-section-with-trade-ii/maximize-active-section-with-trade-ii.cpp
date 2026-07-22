#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

// Sparse Table Class to query maximum in O(1)
class SparseTable {
    vector<vector<int>> st;
    vector<int> log_table;
public:
    void init(const vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return;
        int K = log2(n) + 1;
        st.assign(n, vector<int>(K, 0));
        log_table.assign(n + 1, 0);
        
        for (int i = 2; i <= n; i++)
            log_table[i] = log_table[i >> 1] + 1;
            
        for (int i = 0; i < n; i++)
            st[i][0] = arr[i];
            
        for (int j = 1; j < K; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int query(int L, int R) {
        if (L > R) return 0;
        int j = log_table[R - L + 1];
        return max(st[L][j], st[R - (1 << j) + 1][j]);
    }
};

struct Group {
    int start, end, len;
};

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();
        
        // 1. मूल स्ट्रिंग में कुल '1's की संख्या गिनें
        int total_ones = 0;
        for (char c : s) if (c == '1') total_ones++;

        // 2. सभी '0' के लगातार ब्लॉक्स (Groups) को स्टोर करें
        vector<Group> zero_groups;
        for (int i = 0; i < n; ) {
            if (s[i] == '0') {
                int j = i;
                while (j < n && s[j] == '0') j++;
                zero_groups.push_back({i, j - 1, j - i});
                i = j;
            } else {
                i++;
            }
        }

        int m = zero_groups.size();
        
        // यदि 2 से कम '0' ग्रुप्स हैं, तो कोई भी '1' ब्लॉक दो '0' से घिरा नहीं हो सकता
        if (m < 2) {
            return vector<int>(queries.size(), total_ones);
        }

        // 3. दोAdjacent '0' ब्लॉक्स की संयुक्त लंबाई (Merge Lengths) निकालें
        vector<int> merge_lengths(m - 1);
        for (int i = 0; i < m - 1; i++) {
            merge_lengths[i] = zero_groups[i].len + zero_groups[i + 1].len;
        }

        SparseTable st;
        st.init(merge_lengths);

        // 4. किसी विशिष्ट ग्रुप की [L, R] के अंदर की प्रभावी लंबाई निकालने का लैम्ब्डा फ़ंक्शन
        auto get_overlap_len = [&](int idx, int L, int R) {
            int s_pos = max(zero_groups[idx].start, L);
            int e_pos = min(zero_groups[idx].end, R);
            return max(0, e_pos - s_pos + 1);
        };

        vector<int> ans;
        for (const auto& q : queries) {
            int L = q[0], R = q[1];

            // Binary Search से पहला ऐसा ग्रुप ढूंढें जो L सीमा को पार करता हो या उसके बाद हो
            int i_min = m;
            int low = 0, high = m - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (zero_groups[mid].end >= L) {
                    i_min = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            // Binary Search से आखिरी ऐसा ग्रुप ढूंढें जो R सीमा से पहले शुरू होता हो
            int i_max = -1;
            low = 0; high = m - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (zero_groups[mid].start <= R) {
                    i_max = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            
            // चूँकि हमें i और i+1 को मिलाना है, इसलिए वैलिड i की अधिकतम सीमा i_max - 1 होगी
            i_max = i_max - 1;

            int max_gain = 0;

            if (i_min <= i_max) {
                // सीमा वाले इंडेक्स (i_min और i_max) को मैन्युअली चेक करें क्योंकि वे कटे (truncated) हो सकते हैं
                max_gain = max(max_gain, get_overlap_len(i_min, L, R) + get_overlap_len(i_min + 1, L, R));
                max_gain = max(max_gain, get_overlap_len(i_max, L, R) + get_overlap_len(i_max + 1, L, R));

                // जो ग्रुप पूरी तरह से [L, R] के अंदर हैं, उनके लिए Sparse Table से O(1) में मैक्सिमम लें
                if (i_min + 1 <= i_max - 1) {
                    max_gain = max(max_gain, st.query(i_min + 1, i_max - 1));
                }
            }

            // कुल एक्टिव सेक्शन्स = मूल '1's + नेट गेन
            ans.push_back(total_ones + max_gain);
        }

        return ans;
    }
};
