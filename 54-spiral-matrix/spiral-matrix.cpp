class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int m=matrix.size();
        int n=matrix[0].size();
        int startrow=0;
        int endrow=m-1;
        int startcoln=0;
        int endcoln=n-1;
        while(startrow<=endrow && startcoln<=endcoln){
            //top
            for(int j=startcoln;j<=endcoln;j++){
                ans.push_back(matrix[startrow][j]);
            }
            //right
            for(int i=startrow+1;i<=endrow;i++){
                ans.push_back(matrix[i][endcoln]);
            }
            //bottom
            for(int j=endcoln-1;j>=startcoln;j--){
                if(startrow==endrow){
                    break;
                }
                ans.push_back(matrix[endrow][j]);
            }
            //left
            for(int i=endrow-1;i>=startrow+1;i--){
                if(startcoln==endcoln){
                    break;
                }
                ans.push_back(matrix[i][startcoln]);
            }
            startrow++;
            startcoln++;
            endrow--;
            endcoln--;
        }
        return ans;
    }
};