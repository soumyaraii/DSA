class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // vector<vector<string>> ans;
        // vector<string> used;
        // for(int i=0; i<strs.size(); i++){
        //     string s1=strs[i];
        //     vector<string> op;
        //     op.push_back(s1);
        //     used.push_back(s1);
        //     for(int j=i+1; j<strs.size(); j++){
        //         // for(int ch:used){
        //         //     if(ch==strs[j]){
                        
        //         //     }
        //         // }
        //         string s2=strs[j];
        //         sort(s1.begin(), s1.end());
        //         sort(s2.begin(), s2.end());
        //         if(s1==s2){
        //             op.push_back(strs[j]);
        //             used.push_back(s2);
        //         }
        //     }
        //     ans.push_back(op);
        // }
        // return ans;

        int n = strs.size();
        // Pair: {sorted_string, original_index}
        vector<pair<string, int>> sortedPairs(n);
        
        for (int i = 0; i < n; i++) {
            string key = strs[i];
            sort(key.begin(), key.end());
            sortedPairs[i] = {key, i};
        }

        sort(sortedPairs.begin(), sortedPairs.end());
        vector<vector<string>> ans;
        int i = 0;
        while (i < n) {
            vector<string> group;
            group.push_back(strs[sortedPairs[i].second]);
            // Collect all identical sorted keys (anagrams)
            int j = i + 1;
            while (j < n && sortedPairs[j].first == sortedPairs[i].first) {
                group.push_back(strs[sortedPairs[j].second]);
                j++;
            }
            
            ans.push_back(group);
            i = j; // Move index to the next unique string key
        }
        
        return ans;
        
    }
};