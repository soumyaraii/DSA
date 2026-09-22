class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // nums.sort(nums.begin(), nums.end());

        // int freq=1;
        // int i=0;
        // int ans;
        // while(i<nums.size()){
        //     if(nums[i]==nums[i+1]){
        //         freq++;
        //         i++;
        //     }
        //     if(freq>=max){
        //         ans=nums[i];
        //     }
        //     else{
        //         i++;
        //         freq=1;
        //     }
            
        // }

       //2 pointer
        // int max = nums.size() / 2;

        // for(int i = 0; i < nums.size(); i++) {
        //     int freq = 1;

        //     for(int j = i + 1; j < nums.size(); j++) {
        //         if(nums[i] == nums[j]) {
        //             freq++;
        //         }
        //     }

        //     if(freq > max) {
        //         return nums[i];
        //     }
        // }

        // return -1;


        //Boyer-Moore Voting Algorithm
        int ans=nums[0];
        int count=1;
        for(int i=1;i<nums.size(); i++){
            if(count==0){
                ans=nums[i];
            }
            if(ans==nums[i]){
                count++;
            }
            else{
                count--;
            }
        }

        return ans;
    }
};