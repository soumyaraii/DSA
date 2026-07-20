class Solution {
public:
//what we want is that the person at kth index finishes 
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans=0;
        int i=0;
        while (tickets[k] > 0) {
            if (tickets[i] > 0) {
                tickets[i]--;
                ans++;
            }
            i = (i + 1) % tickets.size();
        }
        return ans;
    }
};