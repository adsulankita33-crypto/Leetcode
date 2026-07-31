class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {

        int rows = mat.size();
        int cols = mat[0].size();

        int maxOnes = -1;
        int rowIndex = 0;

        for (int i = 0; i < rows; i++) {

            int rowSum = 0;

            for (int j = 0; j < cols; j++) {
                rowSum += mat[i][j];
            }

            if (rowSum > maxOnes) {
                maxOnes = rowSum;
                rowIndex = i;
            }
        }

        return {rowIndex, maxOnes};
    }
};