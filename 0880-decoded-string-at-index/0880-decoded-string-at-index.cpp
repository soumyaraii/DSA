class Solution {
public:
    struct Node {
        string str;          // letters between two digits
        long long start;     // starting index of this block
        long long before;    // length before the digit
    };

    string decodeAtIndex(string s, int k) {
        stack<Node> st;

        long long len = 0;
        Node curr;

        curr.str = "";
        curr.start = 0;
        curr.before = 0;

        for (char ch : s) {
            if (isalpha(ch)) {
                curr.str += ch;
                len++;

                if (len == k)
                    return string(1, ch);
            }
            else {
                curr.before = len;
                st.push(curr);

                len *= (ch - '0');

                if (len >= k)
                    break;

                curr.str = "";
                curr.start = len;
                curr.before = 0;
            }
        }

        while (!st.empty()) {
            Node t = st.top();
            st.pop();

            long long prefix = t.before;

            k %= prefix;
            if (k == 0)
                k = prefix;

            if (k > t.start) {
                return string(1, t.str[k - t.start - 1]);
            }
        }

        return "";
    }
};