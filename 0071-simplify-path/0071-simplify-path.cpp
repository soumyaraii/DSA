class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;

        string curr="";
        for(char ch:path){
            if(ch!='/'){
                curr+=ch;
            }
            else{ 
                if(curr==".." and !s.empty()){
                    s.pop();
                } 
                else if(curr=="." or curr=="" or (curr==".." and s.empty())){
                    // continue;
                }
                else{
                    s.push(curr);
                }

                curr="";
            }
        }

        if(!curr.empty()){
            if(curr==".." and !s.empty()){
                s.pop();
            }
            else if(curr=="." or curr=="" or (curr==".." and s.empty())){
            }
            else{
                s.push(curr);
            }
        }

        vector <string> v;
        while(!s.empty()){
            v.push_back(s.top());
            s.pop();
        }

        if(v.empty()){
            return "/";
        }

        string ans="/";
        for (int i = (int)v.size() - 1; i > 0; i--) {
            ans+=v[i];
            ans+="/";
        }
        if(!v.empty()){
            ans+=v[0];
        }
        return ans;
    }
};