class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // vector<int> last(128, -1);
        // int left=0;
        // int ans=0;

        // for(int right=0; right<s.size(); right++){
        //     if(last[s[right]]>=left){
        //         left=last[s[right]]+1;
        //     }

        //     last[s[right]]=right;
        //     ans=max(ans,right-left+1);
        // }
        // return ans;
        
        vector<int> last(256, -1);   // last seen index of each char
        int ans = 0, start = 0;
        for (int i = 0; i < s.size(); i++) {
            if (last[s[i]] >= start)      // duplicate inside current window
                start = last[s[i]] + 1;   // jump past the old occurrence
            last[s[i]] = i;               // update last seen position
            ans = max(ans, i - start + 1);
        }
        return ans;


    }
};