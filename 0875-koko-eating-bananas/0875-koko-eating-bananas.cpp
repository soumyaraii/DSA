class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());

        int low=1;
        int high=piles[piles.size()-1]; //values not index

        if(piles.size()==h){
            return piles[piles.size()-1];
        }

        int mid=0;
        int ans;
        while(low<high){
            int ho=0;
            mid=low+(high-low)/2;
            for(int i=0; i<piles.size();i++){
                if(piles[i]<=mid){
                    ho+=1;
                }
                else{
                    ho+=ceil((double)piles[i]/mid); //IMP
                }
            }
            //cout<<ho<<" ";

            if(ho>h){
                low=mid+1;
            }
            else{
                ans=mid;
                high=mid;
            }
        }
        return ans;
    }
};