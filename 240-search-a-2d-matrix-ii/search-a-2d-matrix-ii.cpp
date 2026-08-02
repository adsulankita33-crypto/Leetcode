class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=0;
        int coln=matrix[0].size()-1;
        while(rows<matrix.size() && coln>=0){
            if(matrix[rows][coln]==target){
                return true;
            }
            else if(matrix[rows][coln]>target){
                coln--;
            }
            else{
                rows++;
            }
        }
        return false;
    }
};