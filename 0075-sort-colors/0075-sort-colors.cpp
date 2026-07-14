class Solution {
public:
    void sortColors(vector<int>& nums) {
        int z=0;
        int o=0;
        int t=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){
                z++;
            }
            else if(nums[i]==1){
                o++;
            }
            else{
                t++;
            }
        }
        nums.clear();
        while(z--){
            nums.push_back(0);
        }
        while(o--){
            nums.push_back(1);
        }
        while(t--){
            nums.push_back(2);
        }
    }
};