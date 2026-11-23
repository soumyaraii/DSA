class Solution {
public:
string s;
vector<string> words;
    // bool rec(int x){
    //     //base case
    //     if(x<0){
    //         return true;
    //     }
    //     //rec case
    //     for(int w=words.size()-1; w>=0; w--){
    //         string word=words[w];
    //         int l=word.size()-1;
    //         int i=x;
    //         while(i>=0 and l>=0 and s[i]==word[l]){
    //             i--;
    //             l--;
    //         }
    //         //entire word has matched
    //         if(l<0){
    //             //all should match
    //             if(rec(i)){
    //                 return true;
    //             }
    //         }
    //     }
    //     return false;  
    // }
int arr[301];
    bool dp(int x){
        //base case
        if(x<0){
            return true;
        }
        //rec case

        if(arr[x]!=-1){
            return arr[x];
        }

        for(int w=words.size()-1; w>=0; w--){
            string word=words[w];
            int l=word.size()-1;
            int i=x;
            while(i>=0 and l>=0 and s[i]==word[l]){
                i--;
                l--;
            }
            //entire word has matched
            if(l<0){
                //all should match
                if(dp(i)){
                    arr[x]=true;
                    return arr[x];
                }
            }
        }
        return arr[x]=false;  
    }

    bool wordBreak(string str, vector<string>& wordDict) {
        //start from back, go in words, match end of word with str[x]
        s=str;
        words=wordDict;
        int n=str.size();
        int m=wordDict.size();
        memset(arr, -1, sizeof(arr));
        return dp(n-1);
    }
};