class Solution {
public:
    string decodeString(string s) {
        stack<pair<int, string>> st;
        string curr = "";
        int num = 0;
        for (char ch : s) {
            if (isdigit(ch)) {
                num=num*10+(ch-'0');
            }
            else if (ch=='[') {
                // Save current state
                st.push({num, curr});

                // Start fresh for the substring inside brackets
                num=0;
                curr="";
            }
            else if (ch==']') {
                // Get previous state
                int repeat = st.top().first;
                string prev = st.top().second;
                st.pop();

                // Repeat current string
                string temp = "";
                while (repeat--) {
                    temp += curr;
                }

                // Append to previous string
                curr = prev + temp;
            }
            else {
                curr += ch;
            }
        }
        return curr;
    }
};