class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for (string op : operations){
            //switch(ch): doesnt work on string
            if (op == "D") {
                int ans=2*st.top();
                st.push(ans);
            }
            else if (op == "C") {
                st.pop();
            }
            else if (op == "+") {
                int a=st.top();
                int temp=a;
                st.pop();
                a+=st.top();
                st.push(temp);
                st.push(a);
            }
            else {
                // it's a number
                int no=stoi(op); //IMP
                st.push(no);
            }
        }

        int ans=0;
        while(st.empty()!=true){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};