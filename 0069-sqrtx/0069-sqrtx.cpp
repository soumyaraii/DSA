class Solution {
public:
    int mySqrt(int x) {
        if(x==0){
            return 0;
        }
        int ans;
        int low=1;
        int high=x;
        while(low<=high){
            int mid=low+(high-low)/2;

            if((long long)mid*mid==x){
                return mid;
            }
            if((long long)mid*mid<x){
                ans=mid;
                low=mid+1;
            }
            if((long long)mid*mid>x){
                high=mid-1;
            }
        }
        return ans;
    }
};