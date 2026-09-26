class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // int maxprod=INT_MIN;
        // int currprod=1;
        // for(int x:nums){
        //     currprod=max(1,currprod*x);
        //     if(currprod==0 and x>0){
        //         currprod=x;
        //     }
        //     // if(x<0 and nums.size()==1){
        //     //     currprod=nums[0];
        //     // }
        //     maxprod=max(maxprod,currprod);
        // }
        
        // if(nums.size()==1){
        //     return nums[0];
        // }
        int maxrn = nums[0];
        int minrn = nums[0];
        int res = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int x = nums[i];

            int oldMax = maxrn;
            int oldMin = minrn;

            maxrn = max(x, max(oldMax * x, oldMin * x));
            minrn = min(x, min(oldMax * x, oldMin * x));

            res = max(res, maxrn);
        }
        return res;
    }
};