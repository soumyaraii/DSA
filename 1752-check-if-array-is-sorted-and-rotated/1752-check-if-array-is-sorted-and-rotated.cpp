class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i]){
                cnt++;
            }
        }
        if(nums[n-1]>nums[0]){
            cnt++;
        }
        return cnt<=1;


//         int n = nums.size();
//         int count = 0;
//         bool ans=false;

//         for(int i=0; i<nums.size()-1; i++){
//             if(nums[i]<nums[i+1]){
//                 count++;
//             }
//             else{
//                 break
//             }
//         }
// //size-index-= x
//         vector<int> a;
//         int x=nums.size()-i;

//         for(int j=count+1; i<nums.size()-1; i++){
//             a.push_back(nums[j]);
//         }

//         for(int k=0; i<nums.size()-1; i++){
//             a.push_back(nums[j]);
//         }


    }
};