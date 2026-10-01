class Solution {
public:
    int strStr(string haystack, string needle) {
        int idx=-1;
        int i=0;
        while(i<haystack.size()){
            string s=haystack.substr(i,needle.size());
            if(s==needle){
                idx=i;
                break;
            }
            i++;
        }
        return idx;
    }
};