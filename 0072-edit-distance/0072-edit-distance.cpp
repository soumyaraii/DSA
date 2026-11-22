class Solution {
public:
//time complexity- no of states*transition time =o(501*501)*o(3)
//o(3) represents the options 
//algorithm- 10*8
    string s, t;
    int dp[501][501];
    int rec(int x, int y){
        //current statement: F(x,y)
        // stopping point

        //x and y represent last index of string not length which why we do +1
        if(x<0 and y>=0){
            //current state: F(-1,y):y+1
            return y+1;
        }
        if(y<0 and x>=0){
            //current state: F(-1,x)
            return x+1;
        }
        if(x<0 and y<0){
            return 0;
        }

        if(dp[x][y] != -1) {
            return dp[x][y];
        }

        if(s[x]==t[y]){
            int ans=rec(x-1, y-1);
            return dp[x][y]=ans;
        }

        //insertion
        int op1=rec(x, y-1);
        //deletion
        int op2=rec(x-1, y);
        //replace
        int op3=rec(x-1, y-1);

        int ans=1+min(op1, min(op2, op3));
        return dp[x][y]=ans;

        //current
    }
    int minDistance(string str, string ptr) {
        s=str;
        t=ptr;

        int n=str.length()-1;
        int m=ptr.length()-1;

        memset(dp, -1, sizeof(dp));
        int ans=rec(n,m);
        return ans;

        // vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // for (int i = 0; i <= m; ++i) {
        //     dp[i][0] = i;
        // }
        // for (int j = 0; j <= n; ++j) {
        //     dp[0][j] = j;
        // }
        // for(int i=1; i<=m; i++){
        //     for(int j=1; j<=n; j++){
        //         if (word1[i - 1] == word2[j - 1]) {
        //             dp[i][j] = dp[i - 1][j - 1];
        //         } 
        //         else {
        //             dp[i][j] = 1 + min({
        //                 dp[i - 1][j - 1], // replace
        //                 dp[i - 1][j],     // delete
        //                 dp[i][j - 1]      // insert
        //             });
        //         }
        //     }
        // }
        // return dp[m][n];

    }
};