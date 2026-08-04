class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>matrix(n,vector<int>(n));
        int startrow=0;int endrow=n-1;
        int startcoln=0;int endcoln=n-1;
        int num=1;
        while(startrow<=endrow && startcoln<=endcoln){
         for(int j=startcoln;j<=endcoln;j++){
            matrix[startrow][j]=num++;
         }
         startrow++;
         for(int i=startrow;i<=endcoln;i++){
            matrix[i][endcoln]=num++;
         }
         endcoln--;
         if(startcoln<=endcoln){
            for(int j=endcoln;j>=startcoln;j--){
                matrix[endrow][j]=num++;
            }
            endrow--;
         }
         if(startrow<=endrow){
            for(int i=endrow;i>=startrow;i--){
                matrix[i][startcoln]=num++;
            }
            startcoln++;
         }
        }
        return matrix;
    }
};