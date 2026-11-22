class Solution {
public:
    // int rec(vector<int>& nums,int start, int end){
    //     int prev2=0;
    //     int prev1 = 0;

    //     for (int i = start; i <= end; i++) {
    //         int curr = max(prev1, nums[i]+prev2);
    //         prev2=prev1;
    //         prev1=curr;
    //     }
    //     return prev1;
    // }

    int rec(vector<int>& nums,int start, int end){
        vector<int> dp(nums.size(), -1);
        //base case
        dp[start]=nums[start];
        if(start==end){
            return dp[start];
        }
        dp[start+1]=max(nums[start+1],nums[start]);
        // rec case
        for(int i=start+2; i<=end; i++){
            dp[i]=max(nums[i]+dp[i-2], dp[i-1]);
        }

        return dp[end];
    }


    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        if(n==0){
            return 0;
        }
        
        int op1=rec(nums,0,n-2);
        int op2=rec(nums,1,n-1);
        

        return max(op1,op2);
    }
};