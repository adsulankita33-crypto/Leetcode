class Solution {
private:
    // शिल्लक राहिलेल्या अवयवांसाठी कमीत कमी अंक शोधणारे फंक्शन
    string get_min_digits_string(int c2, int c3, int c5, int c7) {
        c2 = max(0, c2); c3 = max(0, c3); c5 = max(0, c5); c7 = max(0, c7);
        int best_len = INT_MAX;
        string best_str = "";

        // 2 आणि 3 चे संयोजन (Combinations) शोधण्यासाठी लूप
        for (int n9 = 0; n9 <= c3 / 2 + 1; ++n9) {
            for (int n8 = 0; n8 <= c2 / 3 + 1; ++n8) {
                for (int n6 = 0; n6 <= 1; ++n6) {
                    for (int n4 = 0; n4 <= 2; ++n4) {
                        for (int n3 = 0; n3 <= 1; ++n3) {
                            for (int n2 = 0; n2 <= 2; ++n2) {
                                int rem_2 = c2 - (3 * n8 + n6 + 2 * n4 + n2);
                                int rem_3 = c3 - (2 * n9 + n6 + n3);
                                if (rem_2 <= 0 && rem_3 <= 0) {
                                    string s = "";
                                    s.append(c5, '5');
                                    s.append(c7, '7');
                                    s.append(n9, '9');
                                    s.append(n8, '8');
                                    s.append(n6, '6');
                                    s.append(n4, '4');
                                    s.append(n3, '3');
                                    s.append(n2, '2');
                                    sort(s.begin(), s.end());
                                    if (s.length() < best_len || (s.length() == best_len && s < best_str)) {
                                        best_len = s.length();
                                        best_str = s;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return best_str;
    }

public:
    string smallestNumber(string num, long long t) {
        long long temp = t;
        int counts[10] = {0};
        int primes[] = {2, 3, 5, 7};
        
        // t चे 2, 3, 5, 7 मध्ये मूळ अवयव पाडणे
        for (int p : primes) {
            while (temp % p == 0) {
                counts[p]++;
                temp /= p;
            }
        }
        
        // जर t मध्ये 2, 3, 5, 7 व्यतिरिक्त इतर अवयव असतील तर शक्य नाही
        if (temp > 1) return "-1";

        int n = num.length();
        vector<int> pref_2(n + 1, 0), pref_3(n + 1, 0), pref_5(n + 1, 0), pref_7(n + 1, 0);
        vector<bool> has_zero(n + 1, false);

        // प्रिफिक्स (Prefix) मधील अवयवांची पूर्व-गणना
        for (int i = 0; i < n; ++i) {
            has_zero[i + 1] = has_zero[i] || (num[i] == '0');
            int d = num[i] - '0';
            pref_2[i + 1] = pref_2[i] + (d == 2 || d == 6 ? 1 : d == 4 ? 2 : d == 8 ? 3 : 0);
            pref_3[i + 1] = pref_3[i] + (d == 3 || d == 6 ? 1 : d == 9 ? 2 : 0);
            pref_5[i + 1] = pref_5[i] + (d == 5 ? 1 : 0);
            pref_7[i + 1] = pref_7[i] + (d == 7 ? 1 : 0);
        }

        // जर 'num' स्वतःच अटी पूर्ण करत असेल
        if (!has_zero[n]) {
            if (pref_2[n] >= counts[2] && pref_3[n] >= counts[3] && pref_5[n] >= counts[5] && pref_7[n] >= counts[7]) {
                return num;
            }
        }

        // मागून पुढे येत मोठा अंक बदलण्याचा प्रयत्न करणे (Greedy approach)
        for (int i = n - 1; i >= 0; --i) {
            if (has_zero[i]) continue;
            int curr_d = num[i] - '0';
            for (int d = curr_d + 1; d <= 9; ++d) {
                int c2 = pref_2[i] + (d == 2 || d == 6 ? 1 : d == 4 ? 2 : d == 8 ? 3 : 0);
                int c3 = pref_3[i] + (d == 3 || d == 6 ? 1 : d == 9 ? 2 : 0);
                int c5 = pref_5[i] + (d == 5 ? 1 : 0);
                int c7 = pref_7[i] + (d == 7 ? 1 : 0);

                int rem_2 = counts[2] - c2;
                int rem_3 = counts[3] - c3;
                int rem_5 = counts[5] - c5;
                int rem_7 = counts[7] - c7;

                string suff_str = get_min_digits_string(rem_2, rem_3, rem_5, rem_7);
                int rem_len = n - 1 - i;

                if ((int)suff_str.length() <= rem_len) {
                    string ans_suff = string(rem_len - suff_str.length(), '1') + suff_str;
                    return num.substr(0, i) + to_string(d) + ans_suff;
                }
            }
        }

        // जर समान लांबीमध्ये शक्य नसेल तर मोठी लांबी तयार करणे
        string suff_str = get_min_digits_string(counts[2], counts[3], counts[5], counts[7]);
        int target_len = max(n + 1, (int)suff_str.length());
        return string(target_len - suff_str.length(), '1') + suff_str;
    }
};