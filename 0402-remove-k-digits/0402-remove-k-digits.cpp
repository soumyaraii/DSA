class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        for(char ch:num){
            // int n=ch-'0';
            while(!s.empty() and s.top()>ch and k>0){
                s.pop();
                k--;
            }
            s.push(ch);
        }

        while(k>0 and !s.empty()){
            s.pop();
            k--;
        }

        string result;
        while (!s.empty()) {
            result += s.top();
            s.pop();
        }
        reverse(result.begin(), result.end());

        // int ans=stoi(result);
        // result=to_string(ans);
        // return result;
        int pos = result.find_first_not_of('0');
    
        // 2. If the string contains only zeros, return a single "0"
        //string::npos: This is a constant that stands for "no position found"
        if (pos == -1) {
            return "0";
        }
        
        // 3. Delete everything from index 0 up to the first non-zero character
        return result.substr(pos);

    }
};