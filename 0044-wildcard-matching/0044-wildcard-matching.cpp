class Solution {
public:
string s, p;
//iterative dp-
    // bool rec(int x, int y){
    //     dp[0][0]=true;
    //     if(x>0 and y<0){
    //         dp[x][0]=false;
    //     }

    //     //sarts from y=1 because of shifting
    //     for(int y=1; y<m; y++){
    //         if(p[y-1]=='*'){
    //             dp[0][y]=dp[0][y-1];
    //         }
    //         else{
    //             dp[0][y]=false;
    //         }
    //     }

    //     // if(s[x]==p[y] or p[y]=='?'){
    //     //     return rec(x-1, y-1);
    //     // }
    //     for(int x=1; x<=n; x++){
    //         for(int y=1; y<=m; y++){
    //             if(s[x-1]==p[y-1] or p[y-1]=='?'){
    //                 dp[x][y]=dp[x-1][y-1];
    //             }
    //         }
    //     }
    //     if(p[y]=='*'){
    //         bool op1=rec(x, y-1);
    //         bool op2=rec(x-1, y);
    //     }
    // }
    // bool rec(int x, int y){
    //     if(x<0 and y<0){
    //         return true;
    //     }
    //     if(x>=0 and y<0){
    //         return false;
    //     }

    //     if(y>=0 and x<0){
    //         if(p[y]=='*'){
    //             //not automatically true because p might be a* or something like that
    //             return rec(x, y-1);
    //         }
    //         return false;
    //     }
    //     if(s[x]==p[y] or p[y]=='?'){
    //         return rec(x-1, y-1);
    //     }
    //     bool op1=false;
    //     bool op2=false;
    //     if(p[y]=='*'){
    //         op1=rec(x, y-1);   //* take empty value
    //         op2=rec(x-1, y);   //* take empty value but still exists
    //     }

    //     bool ans=op1 or op2;
    //     return ans;

    // }
int dp[2001][2001];
    bool rec(int x, int y){
        if(x<0 and y<0){
            return true;
        }
        if(y<0){
            return false;
        }

        if(x<0){
            if(p[y]=='*'){
                //not automatically true because p might be a* or something like that
                // return dp[x][y]=rec(x, y-1); //we cant return this because x<0
                return rec(x,y-1);
            }
            return false;
        }

        if(dp[x][y]!=-1){
            return dp[x][y];
        }
        
        if(s[x]==p[y] or p[y]=='?'){
            return dp[x][y]=rec(x-1, y-1);
        }
        bool op1=false;
        bool op2=false;
        if(p[y]=='*'){
            op1=rec(x, y-1);   //* take empty value
            op2=rec(x-1, y);   //* take empty value but still exists
        }

        bool ans=op1 or op2;
        return dp[x][y]=ans;
    }
    bool isMatch(string str, string ptr) {
        int n=str.size();
        int m=ptr.size();
        s=str;
        p=ptr;
        memset(dp, -1, sizeof(dp));
        //rec from back
        return rec(n-1, m-1);
    }
};