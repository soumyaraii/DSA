class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans;
        // vector<int> ans(nums.size(), -1);
        stack<int> s;

        for(int i=0; i<nums.size(); i++){
            bool greater=false;
            for (int k=1; k<nums.size(); k++) {
                int j=(i + k) % nums.size();    //IMP
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

        // for(int i=0; i<nums.size()-1; i++){
        //     ans[i]=-1;
        //     for(int j=i+1; j<nums.size(); j++){
        //         if(nums[j]>nums[i]){
        //             ans[i]=nums[j];
        //             s.push(nums[j]);
        //             break;
        //         }
        //     }
        // }

        // ans[nums.size()-1]=-1;
        // while(!s.empty()){
        //     if(s.top()>nums[nums.size()-1]){
        //         ans[nums.size()-1]=s.top();
        //         s.pop();
        //     }
        //     else{
        //         s.pop();
        //     }
            
        // }

        // return ans;

    }
};