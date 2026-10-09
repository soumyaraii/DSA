class Solution {
public:
bool ans=false;
    bool isPowerOfThree(int n) {
        if(n==0){
            return ans;
        }
        if(n==1){
            ans=true;
            return ans;
        }
        if(n%3==0){
            isPowerOfThree(n/3);
        }
        return ans;
    }
};