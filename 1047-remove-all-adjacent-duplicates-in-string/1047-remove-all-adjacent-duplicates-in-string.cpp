class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for(char ch :s){
            if(st.empty()!=true && ch==st.top()){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }

        string ans="";
        while(st.empty()!=true){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};