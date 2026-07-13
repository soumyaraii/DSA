class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans;
        stack<int> s;

        for(int i=0; i<nums.size(); i++){
            bool greater=false;
            for (int k = 1; k<nums.size(); k++) {
                int j = (i + k) % nums.size();
                if(nums[j]>nums[i]){
                    greater=true;
                    ans.push_back(nums[j]);
                    break;
                }
            }
            if(greater==false){
                ans.push_back(-1);
            }
        }

        return ans;
    }
};