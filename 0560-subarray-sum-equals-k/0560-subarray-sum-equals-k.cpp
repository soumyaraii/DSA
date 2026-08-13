class Solution {
public:
int count=0;
    // int fun(vector<int> nums,int i,int j, int sum, int k){
    //     if(i>j){
    //         return sum;
    //     }
         
    //     if(fun(nums, i, j-1, , sum, k)+nums[j]==k){
    //         sum+=nums[j];
    //         return count++;
    //     }
    //     else{
    //         fun(nums, i, j-1,sum, k);
    //     }

    //     return count;
    // }
    int subarraySum(vector<int>& nums, int k) {
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;

            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];

                if (sum == k) {
                    count++;
                }
            }
        }

        return count;
    }
};