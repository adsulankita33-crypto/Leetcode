class Solution {
public:
    bool sumGame(string num) {

        int n = num.size();
        int half = n / 2;

        int leftSum = 0;
        int rightSum = 0;

        int leftQ = 0;
        int rightQ = 0;

        // Calculate sums and '?' counts
        for (int i = 0; i < half; i++) {
            if (num[i] == '?')
                leftQ++;
            else
                leftSum += num[i] - '0';
        }

        for (int i = half; i < n; i++) {
            if (num[i] == '?')
                rightQ++;
            else
                rightSum += num[i] - '0';
        }

        // Difference in number of '?' must be odd
        // => Alice can force unequal sums
        if ((leftQ - rightQ) % 2 != 0)
            return true;

        int diff = leftSum - rightSum;

        // Alice can force unequal sums if the
        // existing difference cannot be perfectly balanced
        return diff != 9 * (rightQ - leftQ) / 2;
    }
};