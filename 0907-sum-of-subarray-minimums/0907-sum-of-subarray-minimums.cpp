class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int mod = 1e9 + 7;

        vector<int> pse(n), nse(n);
        stack<int> s;

        // Previous Smaller Element
        for(int i = 0; i < n; i++) {
            while(!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }

            pse[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        while(!s.empty()) s.pop();

        // Next Smaller Element
        for(int i = n - 1; i >= 0; i--) {
            while(!s.empty() && arr[s.top()] > arr[i]) {
                s.pop();
            }

            nse[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        // Calculate contribution
        long long ans = 0;

        for(int i = 0; i < n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;

            long long contribution = (left * right) % mod;
            contribution = (contribution * arr[i]) % mod;

            ans = (ans + contribution) % mod;
        }

        return ans;
    }
};