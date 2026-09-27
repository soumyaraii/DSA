class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        // for(int i=0; i<prices.size(); i++){
        //     int ele=prices[i];
        //     for(int j=i; j<prices.size(); j++){
        //         ans=max(ans,prices[j]-ele);
        //     }
        // }

        int buyprice=prices[0];
        int profit=0;

        for(int i=1; i<prices.size(); i++){
            if(buyprice>prices[i]){
                buyprice=prices[i];
            }
            profit=max(profit, prices[i]-buyprice);
        }
        return profit;
        
    }
};