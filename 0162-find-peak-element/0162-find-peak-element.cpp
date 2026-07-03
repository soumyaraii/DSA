class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;

        int p=0;
        if(nums.size()<2){
            return 0;
        }

        if(nums[0]>nums[1]){
            return 0;
        }
        if(nums[nums.size()-1]>nums[nums.size()-2]){
            return nums.size()-1;
        }
        
        while(low<high){
            int mid=low+(high-low)/2;

            if(nums[mid-1]<nums[mid] and nums[mid+1]<nums[mid] and mid>0 ){
                p=mid;
                break;
            }
            
            if(nums[mid]<nums[mid+1]){
                low=mid+1;
            }
            else{
                high=mid;
            }
        }
        return p;
    }
};