class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int>& op, int k, int n, int no){
        //base case
        if(n==0 and op.size()==k){
            ans.push_back(op);
            return;
        }
        if(n<0 or op.size()>k){
            return;
        }
        //rec case
        for(int i=no; i<10; i++){
            op.push_back(i);
            solve(ans, op, k, n-i, i+1);
            op.pop_back();
            
        }

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> op;
        solve(ans, op, k, n, 1);

        return ans;
    }
};