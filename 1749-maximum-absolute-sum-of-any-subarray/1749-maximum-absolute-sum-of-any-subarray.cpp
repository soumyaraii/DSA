class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxEnding = 0;
        int maxSoFar = 0;

        int minEnding = 0;
        int minSoFar = 0;

        for (int x : nums) {
            // Kadane for MAXIMUM subarray sum
            maxEnding = max(0, maxEnding + x);
            maxSoFar = max(maxSoFar, maxEnding);

            // Kadane for MINIMUM subarray sum
            minEnding = min(0, minEnding + x);
            minSoFar = min(minSoFar, minEnding);
        }

        return max(maxSoFar, abs(minSoFar));
    }
};