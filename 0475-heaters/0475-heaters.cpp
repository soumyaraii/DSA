class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        int j = 0;
        int ans = 0;

        for (int house : houses) {
            while (j + 1 < heaters.size() &&abs(heaters[j + 1] - house) <= abs(heaters[j] - house)) {
                j++;
            }
            ans=max(ans, abs(heaters[j] - house));
        }
        return ans;
    }
};