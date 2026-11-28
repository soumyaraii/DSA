class Solution {
public:
int count;
    bool check(vector<vector<int>>& board, int r, int c, int n){
        //column
        for(int i=0; i<r ;i++){
            if(board[i][c]==1){
                return false;
            }
        }

        int i=r-1;
        int j=c-1;

        while(i>=0 && j>=0){
            if(board[i][j]==1){
                return false;
            }
            i--;
            j--;
        }

        int k=r-1;
        int l=c+1;

        while(k>= 0 && l<n){
            if(board[k][l]==1){
                return false;
            }
            k--;
            l++;
        }

        return true;
    }
    void solve(vector<vector<int>>& board, int r, int n){
        if(r==n){
            count++;
            return;
        }
        for(int c=0; c<n; c++){
            if(check(board, r, c, n)){
                board[r][c]=1;
                solve(board, r+1, n);
                board[r][c]=0;
            }
        }

    }
    int totalNQueens(int n) {
        count=0;
        vector<vector<int>> board(n, vector<int>(n,0));
        solve(board, 0, n);

        return count;
    }
};