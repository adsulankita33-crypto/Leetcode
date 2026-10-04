class Solution {
public:
    bool checkValidString(string s) {

        int low = 0;
        int high = 0;

        for (char ch : s) {

            if (ch == '(') {
                low++;
                high++;
            }

            else if (ch == ')') {
                low--;
                high--;
            }

            else {  // '*'
                low--;
                high++;
            }

            // Minimum open brackets cannot be negative
            if (low < 0) {
                low = 0;
            }

            // No possible valid arrangement
            if (high < 0) {
                return false;
            }
        }

        return low == 0;
    }
};