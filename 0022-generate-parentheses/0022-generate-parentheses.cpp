class Solution {
public:
    vector<string> ans;
    void rec(vector<string>& ans, string& op, int n, int open, int close){
        //base case
        if(op.length()==2*n){
            ans.push_back(op);
            return;
        }
        //rec case
        if(open<n){
            op.push_back('(');
            rec(ans, op, n, open+1, close);
            op.pop_back();
        }

        if(close<open){
            op.push_back(')');
            rec(ans, op, n, open, close+1);
            op.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        string op;
        int open;
        int close;
        rec(ans, op, n, 0, 0);
        return ans;
    }
};