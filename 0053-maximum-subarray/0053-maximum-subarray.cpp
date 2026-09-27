class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cs=0;
        int maxs=INT_MIN;
        if(nums.size()==1){
            return nums[0];
        }

        int minele=INT_MAX;
        // int maxele=INT_MIN;
        for(int j=0; j<nums.size(); j++){
            minele=min(minele,nums[j]);
            maxs=max(maxs, nums[j]);
        }
        cout<<minele<<endl;

        if(maxs<0){
            return maxs;
        }
        for(int i=0; i<nums.size(); i++){
            cs=max(0,cs+nums[i]);
            maxs=max(maxs, cs);
            cout<<cs<<endl;
        }

        return maxs;
    }
};