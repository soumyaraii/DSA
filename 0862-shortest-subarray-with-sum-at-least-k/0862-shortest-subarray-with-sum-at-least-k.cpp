class Solution {
public:
//trying prefix sum
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long> prefix(n + 1, 0);
        
        // Step 1: Compute prefix sums
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
            
        deque <int> d;
        int ans=INT_MAX;
        for(int i=0; i<prefix.size(); i++){
            while (!d.empty() && prefix[i] - prefix[d.front()] >= k) {
                ans = min(ans, i - d.front());
                d.pop_front();
            }
            while (!d.empty() && prefix[i] <= prefix[d.back()]){
                d.pop_back();
            }
            d.push_back(i);
        }
        if (ans==INT_MAX){
            ans=-1;
        }
        return ans;
    }
};
//here sliding window doesnt work
        // int ans=INT_MAX;
        // int length=0;
        // int sum=0;
        // for(int i=0; i<nums.size(); i++){
        //     if(nums[i]==k){
        //         ans=1;
        //         break;
        //     }
        //     if(nums[i]==0){
        //         continue;
        //     }
        //     sum+=nums[i];
        //     d.push_back(i);
        //     // if(nums[i]<k and sum<k){
        //     //     // length++;
        //     // }
        //     //cout<<sum<<endl;
        //     if(sum>k and nums[i+1]>0){
        //         sum-=nums[d.front()];
        //         //cout<<sum<<endl;
        //         d.pop_front();
        //     }
        //     if(sum==k){
        //         if(d.size()<ans){
        //             ans=d.size();
        //         }
        //     }
        // }


        // if(sum==k){
        //     if(d.size()<ans){
        //         ans=d.size();
        //     }
        // }
        // if(ans==INT_MAX){
        //     ans=-1;
        // }
        // return ans;