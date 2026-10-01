class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s==t){
            return true;
        }
        if(s.length()!=t.length()){
            return false;
        }
        vector<int> v(26,0);
        for(char ch:s){
            v[ch-97]++;
        }
        for(char ch:t){
            v[ch-97]--;
        }

        for(int i=0; i<26; i++){
            if(v[i]!=0){
                return false;
            }
        }
        return true;
        
    }
};