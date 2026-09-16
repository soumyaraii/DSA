class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // vector<int> ans;
        // int i=0;
        // int j=nums.size()-1;
        // while(i<nums.size()){
        //     if(nums[i]==nums[i+1] and (ans.empty() or ans.back()!=nums[i])){
        //         ans.push_back(nums[i]);
        //         i++;
        //     }
        //     else{
        //         i++;
        //         continue;
        //     }
        // }

        // return ans.size();

        //2 pointer

        if (nums.empty()) return 0; // Handle empty array case

        int j = 0; // Pointer for the position of unique elements
        for (int i = 1; i < nums.size(); i++) {
            if (nums[j] != nums[i]) {
                nums[++j] = nums[i]; // Move the unique element to the next position
            }
        }
        return j + 1;
    }
};