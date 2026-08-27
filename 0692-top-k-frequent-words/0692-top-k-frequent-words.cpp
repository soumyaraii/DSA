class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        sort(words.begin(), words.end());

        vector<pair<string,int>> freqarr;

        int freq = 1;

        for(int i = 1; i < words.size(); i++) {

            if(words[i] == words[i-1]) {
                freq++;
            }
            else {
                freqarr.push_back({words[i-1], freq});
                freq = 1;
            }
        }

        freqarr.push_back({words.back(), freq});

        sort(freqarr.begin(), freqarr.end(), [](auto &a, auto &b) {

            if(a.second != b.second)
                return a.second > b.second;

            return a.first < b.first;
        });

        vector<string> ans;

        for(int i = 0; i < k; i++) {
            ans.push_back(freqarr[i].first);
        }

        return ans;
    }
};
