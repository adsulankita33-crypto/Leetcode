class Solution {
public:

    // half + middle + reverse(half)
    string makePalindrome(string half, char middle, int n) {

        string ans = half;

        // Odd length -> middle character
        if(n % 2 == 1) {
            ans += middle;
        }

        string rev = half;
        reverse(rev.begin(), rev.end());

        ans += rev;

        return ans;
    }


    string lexPalindromicPermutation(string s, string target) {

        int n = s.size();

        // ----------------------------------
        // STEP 1: Frequency of characters
        // ----------------------------------
        vector<int> freq(26, 0);

        for(char ch : s) {
            freq[ch - 'a']++;
        }


        // ----------------------------------
        // STEP 2: Check palindrome possible
        // ----------------------------------
        int odd = 0;
        char middle = '#';

        for(int i = 0; i < 26; i++) {

            if(freq[i] % 2 == 1) {
                odd++;
                middle = char('a' + i);
            }
        }

        // Palindrome possible nahi hai
        if(odd > 1) {
            return "";
        }


        // ----------------------------------
        // STEP 3: Frequency of first half
        // ----------------------------------
        vector<int> halfFreq(26, 0);

        for(int i = 0; i < 26; i++) {
            halfFreq[i] = freq[i] / 2;
        }

        int halfLen = n / 2;

        string best = "";


        // ==================================================
        // CASE 1:
        // First difference target ke left half mein hai
        // ==================================================

        for(int pos = 0; pos < halfLen; pos++) {

            vector<int> cnt = halfFreq;

            bool possible = true;

            // Target ke prefix ko same rakho
            for(int i = 0; i < pos; i++) {

                int x = target[i] - 'a';

                if(cnt[x] == 0) {
                    possible = false;
                    break;
                }

                cnt[x]--;
            }

            if(!possible) {
                continue;
            }


            // target[pos] se SMALLER nahi,
            // smallest GREATER character chahiye
            for(int c = target[pos] - 'a' + 1;
                c < 26;
                c++) {

                if(cnt[c] == 0) {
                    continue;
                }

                vector<int> temp = cnt;

                // Greater character choose karo
                temp[c]--;

                string half = target.substr(0, pos);

                half += char('a' + c);


                // Baaki characters smallest order mein
                for(int x = 0; x < 26; x++) {

                    while(temp[x] > 0) {
                        half += char('a' + x);
                        temp[x]--;
                    }
                }


                // Complete palindrome
                string candidate =
                    makePalindrome(half, middle, n);


                // Candidate target se greater hai?
                if(candidate > target) {

                    // Smallest answer rakho
                    if(best == "" || candidate < best) {
                        best = candidate;
                    }
                }
            }
        }


        // ==================================================
        // CASE 2:
        // Complete first half == target ka first half
        //
        // Example:
        // s = "aac"
        // target = "abb"
        //
        // half = "a"
        // palindrome = "aca"
        // ==================================================

        vector<int> cnt = halfFreq;

        bool possible = true;

        // Target ka first half exactly banana try karo
        for(int i = 0; i < halfLen; i++) {

            int x = target[i] - 'a';

            if(cnt[x] == 0) {
                possible = false;
                break;
            }

            cnt[x]--;
        }


        if(possible) {

            string half = target.substr(0, halfLen);

            string candidate =
                makePalindrome(half, middle, n);


            // Important:
            // Yahan complete palindrome compare karna hai.
            if(candidate > target) {

                if(best == "" || candidate < best) {
                    best = candidate;
                }
            }
        }


        return best;
    }
};