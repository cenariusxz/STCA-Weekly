class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int nx = 0, no = 0, winx = 0, wino = 0;
        for(int i = 0 ; i <= 2 ; ++ i){
            if(board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X')winx = 1;
            if(board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O')wino = 1;
            if(board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X')winx = 1;
            if(board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O')wino = 1;
        }
        if(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')winx = 1;
        if(board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')wino = 1;
        if(board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')winx = 1;
        if(board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')wino = 1;
        for(int i = 0 ; i <= 2 ; ++ i){
            for(int j = 0 ; j <= 2 ; ++ j){
                if(board[i][j] == 'X')nx ++;
                if(board[i][j] == 'O')no ++;
            }
        }
        if(winx && wino)return 0;
        if(winx)return nx == no+1;
        if(wino)return nx == no;
        return (nx == no+1) || (nx == no);
    }
};
