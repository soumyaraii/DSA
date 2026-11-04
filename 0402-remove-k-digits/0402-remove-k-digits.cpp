class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;
        int count=0;
        string ans=" ";
        for(char ch: num){
            while (!st.empty() && k > 0 && st.back() > ch) {
                st.pop_back();
                k--;
            }
            st.push_back(ch);
        }
        while (k > 0 && !st.empty()) {
            st.pop_back();
            k--;
        }
        
        // Remove leading zeros
        int nonZeroIdx = 0;
        while (nonZeroIdx < st.length() && st[nonZeroIdx] == '0') {
            nonZeroIdx++;
        }
        
        string result = st.substr(nonZeroIdx);
        return result.empty() ? "0" : result;
    }
};