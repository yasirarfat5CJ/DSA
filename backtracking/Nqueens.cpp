class Solution {
public:
   bool isSafe(vector<string>&board,int row,int col,int n){
   for(int j=0;j<n;j++){
    if(board[row][j]=='Q'){
        return false;
    }
   }
    for(int i=0;i<n;i++){
    if(board[i][col]=='Q'){
        return false;
    }
    for(int i=row,j=col;i>=0 && j>=0;i--,j--){
        if(board[i][j]=='Q'){
            return false;
        }
    }
     for(int i=row,j=col;i>=0 && j<n;i--,j++){
        if(board[i][j]=='Q'){
            return false;
        }
    }
    
   }
   return true;
   }
    void Nqueens( vector<string>&board,int row,int n, vector<vector<string>>&ans){
        if(n==row){
            ans.push_back({board});
            return;
        }
        for(int i=0;i<n;i++){
            if(isSafe(board,row,i,n)){
                board[row][i]='Q';
                Nqueens(board,row+1,n,ans);
                board[row][i]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        vector<vector<string>>ans;
        Nqueens(board,0,n,ans);
        return ans;


        
    }
};

/*Step1: we initialize the board with . represents an empty cell
 and we call function board

 step 2 :  in this step our aim is to place a queen in every row
 for that we check it is safe to place  the queen in that row
 
 step3: in this step we check for every that particular row or col and 
 left diagonal and right diagonal is already 'q' is placed or not if placed then we return false

 step4: if true we call for next row

 step4 :backtracting   board[row][i]='.';
 */