class Solution {
public:
    bool isPalindrome(string s) {
        bool ans=true;
        string a="";
        for(int ch:s){
            if(isalnum(ch)){
                a+=tolower(ch);
            }
        }
        int st=0;
        int end=a.size()-1;
        while(st<=end){
            if(a[st]!=a[end]){
                ans=false;
                break;
            }
            st++;
            end--;
        }

        return ans;
    }
};