class Solution {
public:
    vector<char> rec(vector<char>& s,int idx){
        if(idx==s.size()-idx-1 or idx+1==s.size()-idx-1){
            swap(s[idx], s[s.size()-idx-1]);
            return s;
        }

        swap(s[idx], s[s.size()-idx-1]);
        rec(s, idx+1);

        return s;
    }
    void reverseString(vector<char>& s) {
        // int l=0;
        // int r=s.size()-1;
        // while(l<r){
        //     swap(s[l], s[r]);
        //     l++;
        //     r--;
        // }

        // for(int i=0; i<s.size()-1; i++){
        //     cout<<s[i];
        // }
        int idx=0;
        rec(s, idx);
        
    }
};