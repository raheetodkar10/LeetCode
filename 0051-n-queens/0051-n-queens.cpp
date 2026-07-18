class Solution {
public:
    bool isSafe(int row,int col,vector<vector<char>> &board){
        int n=board.size();
        //check 3 directions: (Q can go in 8 directions, but the only applicable are these 3(for a new Q to insert))
        //left horizontal 
        for(int i=0;i<col;i++){
            if(board[row][i]=='Q'){
                //mtlb same row me Q he, so attack hoga
                return false;
            }
        }
        //left upper diagonal
        int i=row-1;
        int j=col-1;
        while(i>=0 && j>=0){   //jb tak valid indexes he
            if(board[i][j]=='Q'){
                return false;
            }
            i--;
            j--;
        }
        //left lower diagonal
        int x=row+1;
        int y=col-1;
        while(x<n && y>=0){  //x + hotoy so x<n and y - otoy so y>=0
            if(board[x][y]=='Q'){
                return false;
            }
            x++;
            y--;
        }
        //ethe pochlo means there is no attack
        return true;
    }
    void storeSolution(vector<vector<char>> &board, vector<vector<string>> &ans, int n){
        vector<string> temp;
        for(int row=0;row<n;row++){
            string output="";  //adhi ek empty string ghayaychi
            for(int col=0;col<n;col++){
                char ch=board[row][col];
                output.push_back(ch);
            }
            //here, ek string ready hogyi
            temp.push_back(output);
        }
        //temp ready hogya
        ans.push_back(temp);  
    }
    void solve(vector<vector<char>> &board, vector<vector<string>> &ans, int n, int col){
        //base case
        if(col>=n){
            storeSolution(board,ans,n);  //board mde ans store karaych
            return;
        }
        //1 case
        for(int row=0;row<n;row++){
            if(isSafe(row,col,board)){
                board[row][col]='Q';
                //baki recursion
                solve(board,ans,n,col+1);  //col+1:current col mde queen placed, now move forward
                //backtracking
                board[row][col]='.';
            }    
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<vector<char>> board(n,vector<char>(n,'.'));  //n*n board initialized with '.' (n is no. of rows and uske andar '.')
        solve(board,ans,n,0);
        //int col=0;
        return ans;    
    }
};