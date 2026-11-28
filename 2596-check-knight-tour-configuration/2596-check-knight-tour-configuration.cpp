class Solution {
public:
    bool rec(vector<vector<int>>& grid, int row, int col, int next){
        int n=grid.size();

        if(next==n*n){
            return true;
        }
        int dr[]={2, 2, 1, 1, -1, -1, -2, -2};
        int dc[]={1, -1, 2, -2, 2, -2, 1, -1};

        for (int k=0; k<8; k++) {
            int nr=row+dr[k];
            int nc=col+dc[k];

            if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                grid[nr][nc] == next) {
                return rec(grid, nr, nc, next + 1);
            }
        }

        return false;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        if (grid.empty() or grid[0].empty() or grid[0][0] != 0){
            return false;
        }
        return rec(grid, 0, 0, 1);

        // int n=grid.size();
        // if (grid[0][0]!=0){
        //     return false;
        // }

        // if(r+2<n and c+1< n and grid[r+2][c+1]==grid[r][c]+1){
        //     r=r+2;
        //     c=c+1;
        //     checkValidGrid(grid);
        // } 
        // else if(r+1<n and c+2< n and grid[r+1][c+2]==grid[r][c]+1){
        //     r=r+1;
        //     c=c+2;
        //     checkValidGrid(grid);
        // }
        // else{
        //     return false;
        // }

        // return true;
    }
};