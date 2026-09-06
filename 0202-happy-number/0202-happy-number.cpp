class Solution {
public:
    bool isHappy(int n) {
        vector<int> store;
        bool bans=false;
        int d;

        while(n!=1){
            for(int s: store){
                if(s==n){
                    return false;
                }
            }

            store.push_back(n);

            int ans=0;
            while(n>0){
                d=n%10;
                n=n/10;
                ans+= pow(d,2);
            }

            n=ans;
        }
        return true;
    }
};