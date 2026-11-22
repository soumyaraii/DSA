class Solution {
public:
//time complexity- no of states*transition time =o(501*501)*o(3)
//o(3) represents the options 
//algorithm- 10*8
    string s, t;
    int dp[501][501];
    // int rec(int x, int y){
    //     //current statement: F(x,y)
    //     // stopping point

    //     //x and y represent last index of string not length which why we do +1
    //     if(x<0 and y>=0){
    //         //current state: F(-1,y):y+1
    //         return y+1;
    //     }
    //     if(y<0 and x>=0){
    //         //current state: F(-1,x)
    //         return x+1;
    //     }
    //     if(x<0 and y<0){
    //         return 0;
    //     }

    //     // if(dp[x][y] != -1) {
    //     //     return dp[x][y];
    //     // }

    //     if(s[x]==t[y]){
    //         int ans=rec(x-1, y-1);
    //         return ans;
    //         // return dp[x][y]=ans;
    //     }

    //     //insertion
    //     int op1=rec(x, y-1);
    //     //deletion
    //     int op2=rec(x-1, y);
    //     //replace
    //     int op3=rec(x-1, y-1);

    //     int ans=1+min(op1, min(op2, op3));
    //     return ans;
    //     // return dp[x][y]=ans;
    // }
    int minDistance(string str, string ptr) {
        s=str;
        t=ptr;

        // int n=str.length()-1;
        // int m=ptr.length()-1;
        int n = str.length();
        int m = ptr.length();

        memset(dp, -1, sizeof(dp));
        // int ans=rec(n,m);

        //iterative- shifting required
        //base cases
        for(int i=0; i<=n; i++){
            dp[i][0]=i;
        }

        for(int j=0; j<=m; j++){
            dp[0][j]=j;
        }

        //we are converting s to t
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1]==t[j-1]){     //f(x-1)(y-1)=dp[x][y]
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    //insertion- we use i since now we have to compare i and j-1 because i+1(inserted value)==j
                    int op1=dp[i][j-1];
                    //deletion 
                    int op2=dp[i-1][j];
                    int op3=dp[i-1][j-1];
                    dp[i][j]=1+min(op1,min(op2, op3));
                }
            }
        }
        return dp[n][m];
        // return ans;
    }
};