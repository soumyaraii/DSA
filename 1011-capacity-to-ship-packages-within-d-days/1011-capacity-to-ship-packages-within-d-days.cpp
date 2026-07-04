class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(), weights.end());
        int high=accumulate(weights.begin(), weights.end(), 0);

        int mid=0;
        int ans=0;
        while(low<high){
            mid=low+(high-low)/2;
            int requiredDays=1;
            int currentWeight=0;

            // Check if capacity = mid is sufficient
            for (int i=0; i<weights.size(); i++) {

                if(currentWeight+weights[i]<=mid) {
                    currentWeight+=weights[i];
                }
                else{
                    requiredDays++;
                    currentWeight=weights[i];
                }
            }

            if (requiredDays>days) {
                low=mid+1;
            }
            else {
                high=mid;
            }
        }

        return low;
    }
};