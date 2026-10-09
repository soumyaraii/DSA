class Solution {
public:
bool ans=true;
    bool rec(string& a, int idx){
        if(a.length()==0 or a.length()==1){
            return true;
        }
        if(idx>a.length()-1-idx){
            return true;
        }
        if(a[idx]!=a[a.length()-1-idx]){
            ans=false;
            return ans;
        }
        rec(a, idx+1);
        return ans;
    }
    bool isPalindrome(string s) {
        // bool ans=true;
        string a="";
        for(int ch:s){
            if(isalnum(ch)){
                a+=tolower(ch);
            }
        }
        // cout<<a;
        // int st=0;
        // int end=a.size()-1;
        // while(st<=end){
        //     if(a[st]!=a[end]){
        //         ans=false;
        //         break;
        //     }
        //     st++;
        //     end--;
        // }
        
        return rec(a,0);
    }
};