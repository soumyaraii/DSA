class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int left=0;
        int ans=0;
        deque<int> dmin;
        deque<int> dmax;

        for(int right=0; right<nums.size(); right++){
            while(!dmax.empty() and nums[dmax.back()]<nums[right]){
                dmax.pop_back();
            }
            dmax.push_back(right);

            while(!dmin.empty() and nums[dmin.back()]>nums[right]){
                dmin.pop_back();
            }
            dmin.push_back(right);

            while(nums[dmax.front()]-nums[dmin.front()]>limit){ //inavlid window

                // remove left element if needed
                if (dmax.front()==left){
                    dmax.pop_front();
                }

                if (dmin.front()==left){
                    dmin.pop_front();
                }
                left++;
            }

            ans=max(ans, right-left+1);
        }
        return ans;
    }
};
//         while(i<=j and j<nums.size()){
//             if(dmin.empty() and dmax.empty()){
//                 dmax.push_back(i);  //both point to same thing
//                 dmin.push_back(j);
//             }

//             while(nums[dmax.front()]-nums[dmin.front()]>limit){
//                 while(!dmax.empty() and nums[dmax.back()]<nums[j]){
//                     dmax.pop_back();
//                 }
//                 dmax.push_back(j);

//                 while(!dmin.empty() and nums[dmin.back()]>nums[j]){
//                     dmin.pop_back();
//                 }
//                 dmin.push_back(i);                

//                 if(nums[dmax.front()]-nums[dmin.front()]>=limit){
//                     ans=max(ans, j-i+1);
//                     j++;
//                 }
//                 else{
//                     i++;
//                 }
//             }

//             ans=max(ans, j-i+1); 
//         }
//         return ans;
//     }
// };