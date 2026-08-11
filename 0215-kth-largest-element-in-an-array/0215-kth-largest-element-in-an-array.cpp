class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //general syntax of a C++ priority_queue is: priority_queue<data_type, container, comparator> pq;

        //Max-heap (default):priority_queue<int> pq;
        //min-heap :  priority_queue<int, vector<int>, greater<int>> pq;

        priority_queue<int, vector<int>, greater<int>> pq;
        for(int x:nums){
            pq.push(x);
            if(pq.size()>k){
                pq.pop();
            }
        }

        return pq.top();
        // vector<int> v;

        // for(int i=0; i<nums.size(); i++){
        //     if(v.size() < k) {
        //         v.push_back(nums[i]);
        //         sort(v.begin(), v.end());
        //     }

        //     else if(nums[i] > v[0]) {
        //         v[0] = nums[i];
        //         int j = 0;
        //         while(j+1<k && v[j] > v[j + 1]) {
        //             swap(v[j], v[j + 1]);
        //             j++;
        //         }
        //     }
        // }
        // return v[0];
    }
};