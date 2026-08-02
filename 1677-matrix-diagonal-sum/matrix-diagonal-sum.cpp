class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int rows=mat.size();
        int coln=mat[0].size();
        int n=mat.size();
        int sum=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<coln;j++){
                if(j==i){
                    sum+=mat[i][j];
                }
                else if(j==n-1-i){
                    sum+=mat[i][j];
                }
            }
        }
        return sum;
    }
};