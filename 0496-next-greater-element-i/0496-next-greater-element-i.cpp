class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // vector<int> ans;
        // for(int i=0; i<nums1.size(); i++){
        //     for(int j=0; j<nums2.size(); j++){
        //         if(nums1[i]==nums2[j]){
        //             bool found=false;
        //             for(int k=j+1; k<nums2.size(); k++){
        //                 if(nums2[k]>nums2[j]){
        //                     ans.push_back(nums2[k]);
        //                     found=true;
        //                     break;
        //                 }
        //             }
        //             if(found==false){
        //                 ans.push_back(-1);
        //             }
        //         }
        //     }
        // }
        // return ans;


        int nge[10001]; 
        stack<int> st;
        for (int num : nums2) {
            // While the current number is greater than the element on top of the stack,
            // it is the next greater element for that stack element.
            while (!st.empty() && st.top() < num) {
                nge[st.top()] = num;
                st.pop();
            }
            // Push the current element onto the stack
            st.push(num);
        }

        // Remaining elements in the stack have no greater element to their right
        while (!st.empty()) {
            nge[st.top()] = -1;
            st.pop();
        }
        vector<int> result;
        result.reserve(nums1.size());
        for (int num : nums1) {
            result.push_back(nge[num]);
        }

        return result;
    }
};