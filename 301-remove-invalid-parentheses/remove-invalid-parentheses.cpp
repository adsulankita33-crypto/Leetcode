class Solution {
public:

    vector<string> ans;

    void backtrack(string &s, int index,
                   int leftCount, int rightCount,
                   int leftRemove, int rightRemove,
                   string current) {

        // Base case
        if (index == s.length()) {

            if (leftRemove == 0 &&
                rightRemove == 0 &&
                leftCount == rightCount) {

                ans.push_back(current);
            }

            return;
        }

        char ch = s[index];

        // Case 1: '('
        if (ch == '(') {

            // Remove '('
            if (leftRemove > 0) {
                backtrack(s, index + 1,
                          leftCount, rightCount,
                          leftRemove - 1, rightRemove,
                          current);
            }

            // Keep '('
            backtrack(s, index + 1,
                      leftCount + 1, rightCount,
                      leftRemove, rightRemove,
                      current + ch);
        }

        // Case 2: ')'
        else if (ch == ')') {

            // Remove ')'
            if (rightRemove > 0) {
                backtrack(s, index + 1,
                          leftCount, rightCount,
                          leftRemove, rightRemove - 1,
                          current);
            }

            // Keep ')' only if there is '(' available
            if (leftCount > rightCount) {
                backtrack(s, index + 1,
                          leftCount, rightCount + 1,
                          leftRemove, rightRemove,
                          current + ch);
            }
        }

        // Case 3: Letter
        else {

            backtrack(s, index + 1,
                      leftCount, rightCount,
                      leftRemove, rightRemove,
                      current + ch);
        }
    }


    vector<string> removeInvalidParentheses(string s) {

        int leftRemove = 0;
        int rightRemove = 0;

        // Find minimum removals
        for (char ch : s) {

            if (ch == '(') {
                leftRemove++;
            }

            else if (ch == ')') {

                if (leftRemove > 0) {
                    leftRemove--;
                }
                else {
                    rightRemove++;
                }
            }
        }

        backtrack(s, 0,
                  0, 0,
                  leftRemove, rightRemove,
                  "");

        // Remove duplicates
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());

        return ans;
    }
};