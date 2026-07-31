class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int coln=matrix[0].size();
        int start=0;
        int end=rows*coln-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            int row=mid/coln;
            int col=mid%coln;
            if(matrix[row][col]==target){
                return true;
            }
            else if(matrix[row][col]<target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return false;
    }
};