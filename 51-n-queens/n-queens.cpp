class Solution {
public:
bool isSafe(vector<string>&board,int row,int coln,int n){
    for(int j=0;j<n;j++){
        if(board[row][j]=='Q'){
            return false;
        }
    }
    for(int i=0;i<n;i++){
        if(board[i][coln]=='Q'){
            return false;
        }
    }
    for(int i=row-1,j=coln-1;i>=0&&j>=0;i--,j--){
        if(board[i][j]=='Q'){
            return false;
        }
    }
    for(int i=row-1, j=coln+1;i>=0&&j<n;i--,j++){
        if(board[i][j]=='Q'){
            return false;
        }
    }
    return true;
}
void nQueen(vector<string>&board,int row,vector<vector<string>>&ans,int n){
    if(row==n){
        ans.push_back(board);
        return;
    }
    for(int j=0;j<n;j++){
      if(isSafe(board,row,j,n)){
        board[row][j]='Q';
      nQueen(board,row+1,ans,n);
      board[row][j]='.';
    }
}
}
    vector<vector<string>> solveNQueens(int n) {
      vector<vector<string>>ans;
      vector<string>board(n,string(n,'.'));
      nQueen(board,0,ans,n);
      return ans;  
    }
};