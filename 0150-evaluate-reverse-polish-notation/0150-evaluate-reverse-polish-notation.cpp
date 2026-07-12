class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> st;
        int result=0;
        for(int i=0; i<tokens.size(); i++){
            if(tokens[i]=="+" or tokens[i]=="-" or tokens[i]=="*" or tokens[i]=="/"){
                int b=st.top();
                st.pop();
                int a=st.top();
                st.pop();
                if (tokens[i]=="+")
                    result=a+b;
                else if (tokens[i]=="-")
                    result=a-b;
                else if (tokens[i]== "*")
                    result=a*b;
                else
                    result=a/b;

                st.push(result);
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }

        return st.top();
    }
};